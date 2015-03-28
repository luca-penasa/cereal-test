#include <cereal/archives/xml.hpp>
#include <cereal/types/polymorphic.hpp>

#include <iostream>
#include <fstream>
#include <classes.h>
using namespace std;



int main()
{



    std::cout << cereal::traits::detail::count_input_serializers<DerivedClass, cereal::XMLInputArchive>::value << std::endl;


  {
    std::ofstream os( "polymorphism_test.xml" );
    cereal::XMLOutputArchive oarchive( os );

    // Create instances of the derived classes, but only keep base class pointers
    std::shared_ptr<BaseClass> ptr1 = std::make_shared<DerivedClass>();
//    std::shared_ptr<BaseClass> ptr2 = std::make_shared<EmbarrassingDerivedClass>();
    oarchive( ptr1 );
  }

  {
    std::ifstream is( "polymorphism_test.xml" );
    cereal::XMLInputArchive iarchive( is );

    // De-serialize the data as base class pointers, and watch as they are
    // re-instantiated as derived classes
    std::shared_ptr<BaseClass> ptr1;
    iarchive( ptr1 );

    // Ta-da! This should output:
    ptr1->sayType();  // "DerivedClassOne"
  }

  return 0;
}
