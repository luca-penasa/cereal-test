#ifndef CLASSES
#define CLASSES

#include <cereal/types/polymorphic.hpp>



// A class derived from BaseClass
class BaseClass
{
public:
  virtual void sayType();

  int x = 10;

private:
  friend class cereal::access;

  template<class Archive>
  void serialize( Archive & ar, const std::uint32_t version )
  {
      ar(CEREAL_NVP( x) );
  }
};

// Another class derived from BaseClass
class DerivedClass : public BaseClass
{
public:
  void sayType();

  float y = 2;


protected:
  friend class cereal::access;

  template<class Archive> void save(Archive & ar, std::uint32_t const version) const
  {
      ar(cereal::base_class<BaseClass> (this), CEREAL_NVP(y));

        std::cout << "saving with dedicated save()";
  }

  template<class Archive> void load(Archive & ar,std::uint32_t const version)
  {
      ar(cereal::base_class<BaseClass> (this), CEREAL_NVP(y));

        std::cout << "loading with dedicated save()";

  }


};


namespace cereal
{
  template <class Archive>
  struct specialize<Archive, DerivedClass, cereal::specialization::member_load_save> {};
  // cereal no longer has any ambiguity when serializing MyDerived
}


// Note that there is no need to register the base class, only derived classes
#endif // CLASSES

