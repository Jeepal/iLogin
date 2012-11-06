<?php
/**
 * TOP API: alipay.user.contract.get request
 * 
 * @author auto create
 * @since 1.0, 2012-11-01 12:40:06
 */
class AlipayUserContractGetRequest
{
	
	private $apiParas = array();
	
	public function getApiMethodName()
	{
		return "alipay.user.contract.get";
	}
	
	public function getApiParas()
	{
		return $this->apiParas;
	}
	
	public function check()
	{
		
	}
	
	public function putOtherTextParam($key, $value) {
		$this->apiParas[$key] = $value;
		$this->$key = $value;
	}
}
