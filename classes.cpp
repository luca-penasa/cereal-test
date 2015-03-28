#include <classes.h>

void BaseClass::sayType()
{
  std::cout << "BaseCLass" << std::endl;
}

void DerivedClass::sayType()
{
  std::cout << "DerivedClass. Wait.. I mean DerivedClassTwo!" << std::endl;
}

// Include any archives you plan on using with your type before you register it
// Note that this could be done in any other location so long as it was prior
// to this file being included
#include <cereal/archives/binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/archives/json.hpp>

// Register DerivedClassOne
CEREAL_REGISTER_TYPE(DerivedClass);

// Register EmbarassingDerivedClass with a less embarrasing name
//CEREAL_REGISTER_TYPE_WITH_NAME(DerivedClass, "DerivedClass");
