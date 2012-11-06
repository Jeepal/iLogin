<?php
/**
 * @file
 * Variable management class for ILogin-module
 */

class iLogin {

	/**
	 * Array of variables
	 *
	 * @access private
	 */
	private $data = array();

	/**
	 * Pirate constructor
	 *
	 * @return object
	 */
	private function __construct( $data ) 
	{
		if( !is_array($data) ) $data = array($data);

		foreach( $data as $name => $value ) {
			$this->set( $name, $value );	
		}

		return $this;
	}

	/**
	 * Pirate constructor
	 *
	 * @return object
	 */
	private function iLogin( $data )
	{
		return $this->__construct( $data );
	}

	/**
	 * Return object instance
	 *
	 * @return object
	 */
	public static function _instance( $data ) 
	{
		static $__this = null;

		if( !$__this ) {
			$__this = new iLogin($data);
		}

		return $__this;
	}

	/**
	 * Set a variable
	 *
	 * @access public
	 * @param string
	 *		$name, variable name
	 * @param mixed
	 *		$value, variable value
	 * @param boolean
	 *		$overlay, overwrite the existing varable
	 * @return mixed
	 */
	function set( $name, $value, $overlay = false )
	{
		if( !$overlay && $this->exists($name, $this->data) ) {
			return false;
		}

		return $this->data[$name] = $value;
	}

	/**
	 * Get a varabile
	 *
	 * @access public
	 * @param string
	 *		$name, variable name
	 * @return mixed
	 */
	function get( $name )
	{
		return $this->exists($name, $this->data) ? $this->data[$name] : false;
	}

	/**
	 * whether the variable exists
	 *
	 * @access public
	 * @param string
	 *		$name, variable name
	 * @return boolean
	 */
	function exists( $name )
	{
		return array_key_exists($name, $this->data);
	}

	/**
	 * Magic methods get
	 *
	 * @see $this->get
	 */
	function __get( $name )
	{
		return $this->get($name);
	}
 
 	/**
	 * Magic methods set
	 *
	 * @see $this->set
	 */
	function __set( $name, $value )
	{
		$this->set( $name, $value );
	}
}