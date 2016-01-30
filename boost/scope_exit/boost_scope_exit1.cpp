#include <boost/scope_exit.hpp>
#include <iostream>

/**
  * @brief Testing BOOST_SCOPE_EXIT macro to trap the scope end 
  * @warning As the macro should run before return, it should return NULL instead it returns a pointer to a heap memory region which has been correctly deallocated 
  * @note Test it at http://melpon.org/wandbox/permlink/mBMZT2qdcFFGN7Rb 
  */
std::string *foo()
{
  std::string *i = new std::string("Test");
  BOOST_SCOPE_EXIT(&i)
  {
    delete i;
    i = NULL;
    std::cout << "[BOOST_SCOPE_EXIT] Delete Successful and pointer set to NULL " << std::endl; 
  } BOOST_SCOPE_EXIT_END
  std::cout << "*i = " << *i << '\n';
  std::cout << "i = " << i << '\n';
  return i;
}

int main()
{
  std::string *j = foo();
  std::cout << "j = " << j << '\n';
  //** If the pointer is not NULL I can assume it's valid while it is not as the delete has been performed 
  //** Uncomment this and get SEGFAULT produced by invalid pointer dereferencing 
  /*
  if(j != NULL)
      std::cout << "*j = " << *j << '\n';
   */
}
