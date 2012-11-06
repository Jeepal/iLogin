<?php
/**
 * TOP API: taobao.promotionmisc.shopbonus.search request
 * 
 * @author auto create
 * @since 1.0, 2012-11-01 12:40:06
 */
class PromotionmiscShopbonusSearchRequest
{
	/** 
	 * 类目筛选
	 **/
	private $categoryList;
	
	/** 
	 * 当前页
	 **/
	private $currentPage;
	
	/** 
	 * 优惠券面额 只支持3,5,10,20,50,100的面额，输入其他面额(比如9)，会被过滤.
	 **/
	private $discounts;
	
	/** 
	 * 有效期至
	 **/
	private $endTime;
	
	/** 
	 * 旺旺ID
	 **/
	private $keyWord;
	
	/** 
	 * 折扣额度 从几折到几折 保留2位小数，第三位四舍五入  格式必须是数字类型的字符串，否则会抛初始化查询条件错误！
	 **/
	private $maxDiscountRate;
	
	/** 
	 * 剩余张数 从几张到几张
	 **/
	private $maxReserveCount;
	
	/** 
	 * 发行张数 从几张到几张
	 **/
	private $maxTotalCount;
	
	/** 
	 * 折扣额度 从几折到几折 保留两位小数，第三位四舍五入  格式必须是数字类型的字符串，否则会抛初始化查询条件错误！
	 **/
	private $minDiscountRate;
	
	/** 
	 * 剩余张数 从几张到几张
	 **/
	private $minReserveCount;
	
	/** 
	 * 发行张数 从几张到几张
	 **/
	private $minTotalCount;
	
	/** 
	 * 页大小
	 **/
	private $pageSize;
	
	/** 
	 * 用户限领  -2表示不限
	 **/
	private $personLimitCount;
	
	/** 
	 * 卖家星级0表示无星级   输入示例值以外的值，会被过滤，比方说输入16,16会被过滤掉
	 **/
	private $sellerRateLevel;
	
	/** 
	 * 商家类型
	 **/
	private $sellerType;
	
	/** 
	 * 使用条件，订单满XX元，输入0，保留两位小数，第三位四舍五入。表示使用条件无限制   格式必须是数字类型的字符串，否则会抛初始化查询条件错误！
	 **/
	private $startFee;
	
	private $apiParas = array();
	
	public function setCategoryList($categoryList)
	{
		$this->categoryList = $categoryList;
		$this->apiParas["category_list"] = $categoryList;
	}

	public function getCategoryList()
	{
		return $this->categoryList;
	}

	public function setCurrentPage($currentPage)
	{
		$this->currentPage = $currentPage;
		$this->apiParas["current_page"] = $currentPage;
	}

	public function getCurrentPage()
	{
		return $this->currentPage;
	}

	public function setDiscounts($discounts)
	{
		$this->discounts = $discounts;
		$this->apiParas["discounts"] = $discounts;
	}

	public function getDiscounts()
	{
		return $this->discounts;
	}

	public function setEndTime($endTime)
	{
		$this->endTime = $endTime;
		$this->apiParas["end_time"] = $endTime;
	}

	public function getEndTime()
	{
		return $this->endTime;
	}

	public function setKeyWord($keyWord)
	{
		$this->keyWord = $keyWord;
		$this->apiParas["key_word"] = $keyWord;
	}

	public function getKeyWord()
	{
		return $this->keyWord;
	}

	public function setMaxDiscountRate($maxDiscountRate)
	{
		$this->maxDiscountRate = $maxDiscountRate;
		$this->apiParas["max_discount_rate"] = $maxDiscountRate;
	}

	public function getMaxDiscountRate()
	{
		return $this->maxDiscountRate;
	}

	public function setMaxReserveCount($maxReserveCount)
	{
		$this->maxReserveCount = $maxReserveCount;
		$this->apiParas["max_reserve_count"] = $maxReserveCount;
	}

	public function getMaxReserveCount()
	{
		return $this->maxReserveCount;
	}

	public function setMaxTotalCount($maxTotalCount)
	{
		$this->maxTotalCount = $maxTotalCount;
		$this->apiParas["max_total_count"] = $maxTotalCount;
	}

	public function getMaxTotalCount()
	{
		return $this->maxTotalCount;
	}

	public function setMinDiscountRate($minDiscountRate)
	{
		$this->minDiscountRate = $minDiscountRate;
		$this->apiParas["min_discount_rate"] = $minDiscountRate;
	}

	public function getMinDiscountRate()
	{
		return $this->minDiscountRate;
	}

	public function setMinReserveCount($minReserveCount)
	{
		$this->minReserveCount = $minReserveCount;
		$this->apiParas["min_reserve_count"] = $minReserveCount;
	}

	public function getMinReserveCount()
	{
		return $this->minReserveCount;
	}

	public function setMinTotalCount($minTotalCount)
	{
		$this->minTotalCount = $minTotalCount;
		$this->apiParas["min_total_count"] = $minTotalCount;
	}

	public function getMinTotalCount()
	{
		return $this->minTotalCount;
	}

	public function setPageSize($pageSize)
	{
		$this->pageSize = $pageSize;
		$this->apiParas["page_size"] = $pageSize;
	}

	public function getPageSize()
	{
		return $this->pageSize;
	}

	public function setPersonLimitCount($personLimitCount)
	{
		$this->personLimitCount = $personLimitCount;
		$this->apiParas["person_limit_count"] = $personLimitCount;
	}

	public function getPersonLimitCount()
	{
		return $this->personLimitCount;
	}

	public function setSellerRateLevel($sellerRateLevel)
	{
		$this->sellerRateLevel = $sellerRateLevel;
		$this->apiParas["seller_rate_level"] = $sellerRateLevel;
	}

	public function getSellerRateLevel()
	{
		return $this->sellerRateLevel;
	}

	public function setSellerType($sellerType)
	{
		$this->sellerType = $sellerType;
		$this->apiParas["seller_type"] = $sellerType;
	}

	public function getSellerType()
	{
		return $this->sellerType;
	}

	public function setStartFee($startFee)
	{
		$this->startFee = $startFee;
		$this->apiParas["start_fee"] = $startFee;
	}

	public function getStartFee()
	{
		return $this->startFee;
	}

	public function getApiMethodName()
	{
		return "taobao.promotionmisc.shopbonus.search";
	}
	
	public function getApiParas()
	{
		return $this->apiParas;
	}
	
	public function check()
	{
		
		RequestCheckUtil::checkMaxListSize($this->categoryList,100,"categoryList");
		RequestCheckUtil::checkMaxListSize($this->discounts,6,"discounts");
		RequestCheckUtil::checkMaxListSize($this->personLimitCount,6,"personLimitCount");
		RequestCheckUtil::checkMaxListSize($this->sellerRateLevel,21,"sellerRateLevel");
	}
	
	public function putOtherTextParam($key, $value) {
		$this->apiParas[$key] = $value;
		$this->$key = $value;
	}
}
