<?php
/**
 * @file
 * page callbacks for the ILogin-module.
 */

// ---------------------------------------------------------------------------------

/**
 * Menu callback; connect the user with their third-party account callback.
 *
 * @access public
 */
function ilogin_auth_callback( $key )
{
	if( array_key_exists( $key, $GLOBALS['ilogin']->platforms ) ) {

		bootstrap_invoke_all( 'callback_'.$key );
	} else {
		return drupal_access_denied();
	}

	drupal_goto();
}

/**
 * Menu callback; connect the user with third-party account.
 *
 * @access public
 */
function ilogin_signin_redirect( $key ) 
{
	if( array_key_exists( $key, $GLOBALS['ilogin']->platforms ) ) {
		
		drupal_goto( ilogin_auth_url($key) );
	} else {
		return drupal_access_denied();
	}

}

/**
 * Third-party account buttton style.
 *
 * @access public
 */
function ilogin_signin_button()
{
	$return = array();
 
	foreach( $GLOBALS['ilogin']->get('platforms') as $key ) {

		$logo = theme('image', array(
			'path' => drupal_get_path('module', 'ilogin') . $GLOBALS['ilogin']->configure[$key]['logo'],
			'alt' => t('Sign in with '.$key)
		));

		$return[] = sprintf( '<a href="javascript:void(0);" class="ilogin" link="%s">%s</a>', $GLOBALS['ilogin']->redirects[$key], $logo );
	}

  return $return;
}

/**
 * Get auth url
 *
 * @access public
 * @param string
 * @return array
 */
function ilogin_auth_url( $key ) 
{
	$auth_url = null;

	if( array_key_exists($key, $GLOBALS['ilogin']->configure) ) {

		$client_id		= $GLOBALS['ilogin']->keys[$key];
		$redirect_uri	= $GLOBALS['ilogin']->callbacks[$key];
		$auth_url		= sprintf($GLOBALS['ilogin']->configure[$key]['authorize'], $client_id, $redirect_uri);
	}

	return $auth_url;
}

/**
 * User login api.
 */
function ilogin_userlogin( $key, $token = array() ) 
{
	global $user, $ilogin;

	$default = array( 'name' => '', 'screen_name' => '', 'access_token' => '');
	$token = array_merge( $default, $token );

	if( !isset($ilogin->configure[$key]) ) {
		return false;
	}

	if( !db_table_exists($table = $ilogin->configure[$key]['table']) ) {
		return false;
	}

	$primaryKey	= $key . '_uid';

	if ( !user_is_logged_in() ) {

		if ($uid = db_select( $table)
			->fields($table, array('uid'))
			->condition($primaryKey, $token[$primaryKey])
			->execute()
			->fetchField()) {
						
			$user = user_load($uid);
		} else {

			$edit = array(
				'name' => $token['screen_name'],
				'pass' => user_password(),
				'init' => '',
				'status' => 1,
				'access' => REQUEST_TIME,
				'roles' => array(2 => 'authenticated user'),
			);

			$user = user_save(NULL, $edit);

			db_merge( $table )
				->key(array($primaryKey => $token[$primaryKey]))
				->fields(array(
					'uid' => $user->uid,
					'access_token' => $token['access_token'],
					'screen_name' => $token['screen_name'],
					'name' => $token['screen_name'],
			))->execute();
		}
	}

	drupal_session_regenerate();

}