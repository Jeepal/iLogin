<?php
/**
 * @file
 * hooks for the ILogin-module.
 */

// ---------------------------------------------------------------------------------

/**
 * Implements hook_callback_taobao.
 */
function ilogin_callback_taobao() 
{
	global $ilogin;

	module_load_include( 'php', 'ilogin', $ilogin->configure['taobao']['api'] );

	if ($_REQUEST['code']) {

		$params = array(
			'grant_type'    => 'authorization_code',
			'client_id'     => $ilogin->keys['taobao'],
			'client_secret' => $ilogin->secrets['taobao'],
			'code'          => $_REQUEST['code'],
			'redirect_uri'  => $ilogin->callbacks['taobao']
		);

		try {

			$request = new TopClient();
			$token = json_decode( $request->curl( 'https://oauth.taobao.com/token', $params ) );

			$data['taobao_uid'] = $token->taobao_user_id;
			$data['access_token'] = $token->access_token;
			$data['screen_name'] = $token->taobao_user_nick;

			ilogin_userlogin('taobao', $data);

		} catch (Exception $e) {
			
		}	
	}
}

/**
 * Implements hook_callback_renren.
 */
function ilogin_callback_renren() 
{
	global $ilogin;

	module_load_include('php', 'ilogin', $ilogin->configure['renren']['api']);
	
	if ($_REQUEST['code']) {

		$request = new RenrenRestApiService;
		
		$params = array(
			'client_id'		=> $ilogin->keys['renren'],
			'client_secret' => $ilogin->secrets['renren'],
			'redirect_uri'	=> $ilogin->callbacks['renren'],
			'grant_type'	=> 'authorization_code',
			'code'			=> $_REQUEST['code'],
		);
		
		try {

			$response = $request->_POST('https://graph.renren.com/oauth/token', $params);

			if( isset($response['error']) ) {
				throw new exception('Invalid ACCESS API URL or params.');
			}

			$token['access_token'] = $response['access_token'];

			$params = array(
				'fields'=>'uid,name',
				'access_token' => $response['access_token']
			);

			try {
				$response = $request->rr_post_curl('users.getInfo', $params);

				if( isset($response['error_code']) && intval($response['error_code']) > 0 ) {
					throw new exception('Invalid USER API URL or params.');
				}

				$user_message = $response[0];

				$token['screen_name'] = $user_message['name'];
				$token['renren_uid'] = $user_message['uid'];

				ilogin_userlogin('renren', $token);

			} catch ( Exception $e ) {
				drupal_set_message( $e->getMessage(), 'error' );
			}

		} catch ( Exception $e ) {
			drupal_set_message( $e->getMessage(), 'error' );
		}

	}
	
}

/**
 * Implements hook_callback_sinaweibo.
 */
function ilogin_callback_weibo() 
{
	global $ilogin;

	module_load_include('php', 'ilogin',  $ilogin->configure['weibo']['api']);

	if ($_REQUEST['code']) {
		 $auth = new SaeTOAuthV2( $ilogin->keys['weibo'], $ilogin->secrets['weibo'] );

		$keys = array();
		$keys['code'] = $_REQUEST['code'];
		$keys['redirect_uri'] = $ilogin->callbacks['weibo'];

		try {
			$token = $auth->getAccessToken( 'code', $keys ) ;

			$client = new SaeTClientV2( $ilogin->keys['weibo'], $ilogin->secrets['weibo'], $token['access_token'] );
			$uid_get = $client->get_uid();
			$weibo_uid = $uid_get['uid'];
			$user_message = $client->show_user_by_id($weibo_uid);

			$data['weibo_uid'] = $token['uid'];
			$data['access_token'] = $token['access_token'];
			$data['screen_name'] = $user_message['screen_name'];
			$data['name'] = $user_message['name'];

			ilogin_userlogin('weibo', $data);

		} catch (OAuthException $e) {
			
		}

	}
}