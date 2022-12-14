/**
*
*@file BrowserHistoryInterface.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief the interface header of the BrowserHistory.
*@date July.4/2021
*
**/
#ifndef BROWSER_HISTORY_INTERFACE_H
#define BROWSER_HISTORY_INTERFACE_H

#include "ListInterface.h"
#include "LinkedList.h"
#include <string>

class BrowserHistoryInterface
{
  public:
  /**
  * @post All memory allocated by the implementing class should be freed. 
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  virtual ~BrowserHistoryInterface(){} 

  /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
  virtual void navigateTo(std::string url) = 0;

  /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  */
  virtual void forward() = 0;

  /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL 
  */
  virtual void back() = 0;

  /**
  * @return the current URL 
  */
  virtual std::string current() const = 0;

  /**
  * @pre The list being passed in is empty
  * @post The current browser history is copied into the given list  
  * @param destination, an empty list of strings
  */
  virtual void copyCurrentHistory(ListInterface<std::string>& destination) =0;

};

#endif