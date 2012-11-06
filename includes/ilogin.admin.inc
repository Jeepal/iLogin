<?php
/**
 * @file
 * Administrative page callbacks for the ILogin-module.
 */

// ---------------------------------------------------------------------------------

/**
 * This is the main configuration form for the admin page.
 */
function ilogin_configuration_form($form, &$form_state)
{
	$form['base'] = array(

		'#type'				=> 'fieldset',
		'#title'			=> t('Base Settings')
	);

	$form['base']['platform'] = array(

		'#type'				=> 'checkboxes',
		'#title'			=> t("Select Platform:"),
		'#required'			=> TRUE,
		'#options'			=> $GLOBALS['ilogin']->configure['Platforms'],
		'#default_value'	=> variable_get('platform', array('weibo')),
	);

	$platforms = array_filter( variable_get( 'platform', array('weibo') ) );

	foreach( $platforms as $platform ) {

		$form[$platform] = array(
			'#type'			=> 'fieldset',
			'#title'		=> t($platform . ' Connect')
		);

		$form[$platform][$platform.'_key'] = array(
			'#type'			=> 'textfield',
			'#title'		=> t("Consumer Key:"),
			'#required'		=> TRUE,
			'#default_value'=> variable_get($platform.'_key', NULL),
		);

		$form[$platform][$platform.'_secret'] = array(
			'#type'			=> 'textfield',
			'#title'		=> t("Consumer Secret:"),
			'#required'		=> TRUE,
			'#default_value'=> variable_get($platform.'_secret', NULL),
		);

	}


	return system_settings_form($form);
}