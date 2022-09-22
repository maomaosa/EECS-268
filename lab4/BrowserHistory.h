/**
*
*@file BrowserHistory.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief the header file of BrowserHistory class
*@date July.4/2021
*
**/

#ifndef BROWSER_HISTORY_H
#define BROWSER_HISTORY_H

#include "BrowserHistoryInterface.h"


class BrowserHistory : public BrowserHistoryInterface
{
	protected:
	LinkedList<std::string>* webpage;
	int length;
	int m_current;

	
	public:
	
	BrowserHistory();
	//@post - initialize nullpter to webpage, 0 to length, 0 to current
	
	
	
  /**
  * @post All memory allocated by the implementing class should be freed. 
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  ~BrowserHistory();
  
  

  /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
  void navigateTo(std::string url);
  //@pre - url must be valid
  //@post - add the url to the webpage history list, if the current is smaller than the length, delete the extra history after the current



  /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  */
  void forward();
  //@post - make the current-- while current != 1
  
  
  

  /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL 
  */
  void back();
  //@post - make the current++ while current < length
  
  

  /**
  * @return the current URL 
  */
  std::string current() const;
  //post - return the current url while the list != 0
  //return - return the current url

  /**
  * @pre The list being passed in is empty
  * @post The current browser history is copied into the given list  
  * @param destination, an empty list of strings
  */
  void copyCurrentHistory(ListInterface<std::string>& destination);
  //@pre - the destination must be valid
  //@post - copy the url from the list to the destination
};


#endif