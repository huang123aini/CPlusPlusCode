#include <iostream>
#include <memory>

int main(int argc, char const *argv[]) {
  /*** OLD:悬浮指针的问题:ref will point to undefined data!!!*/	

  int *ptr = new int(10);
  int *ref = ptr;
  delete ptr;	
  /***NEW: check expired() or lock() to determine if pointer is valid*/

  /*** empty definition*/ 
  std::shared_ptr<int> sptr;

  /*** takes ownership of pointer*/
  sptr.reset(new int);
  *sptr = 10;

  /***get pointer to data without taking ownership*/
  std::weak_ptr<int> weakPtr1 = sptr;

  /*** deletes managed object. acquires new pointer*/

  sptr.reset(new int);
  *sptr = 5;
  /**
   * get pointer to new data without taking ownership
   */
  std::weak_ptr<int> weakPtr2 = sptr;

  /** weakPtr1 is expired */
  if(auto tmp = weakPtr1.lock()) {
  	std::cout << "weakPtr1 value is : " << *tmp << "\n";
  } else {
  	std::cout << "weakPtr1 is expired.\n";
  }

  /** weakPtr2 points to new data (5) */ 
  if(auto tmp = weakPtr2.lock()) {
  	std::cout << "weakPtr2 value is : " << *tmp << "\n";
  } else {
  	std::cout << "weakPtr2 is expired.\n";
  }

  return 0;
}