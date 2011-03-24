<?php
class Bootstrap extends Zend_Application_Bootstrap_Bootstrap
{
	protected function _initView()
	{
		$baseUrl = substr($_SERVER['PHP_SELF'], 0, -9);
		$view = new Zend_View();
		$view->addHelperPath('ZendX/JQuery/View/Helper/', 'ZendX_JQuery_View_Helper');
 
		$view->jQuery()->uiEnable();
		$viewRenderer = new Zend_Controller_Action_Helper_ViewRenderer();
		$viewRenderer->setView($view);
		Zend_Controller_Action_HelperBroker::addHelper($viewRenderer);
		$view->jQuery()->addStylesheet($baseUrl.'js/jquery/css/le-frog/jquery-ui-1.8.11.custom.css')
			 ->setLocalPath($baseUrl.'js/jquery/js/jquery-1.5.1.min.js')
			 ->setUiLocalPath($baseUrl.'js/jquery/js/jquery-ui-1.8.11.custom.min.js');
	}

}

