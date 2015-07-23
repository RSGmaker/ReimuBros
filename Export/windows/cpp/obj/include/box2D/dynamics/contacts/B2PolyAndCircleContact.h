#ifndef INCLUDED_box2D_dynamics_contacts_B2PolyAndCircleContact
#define INCLUDED_box2D_dynamics_contacts_B2PolyAndCircleContact

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/contacts/B2Contact.h>
HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2PolyAndCircleContact)
namespace box2D{
namespace dynamics{
namespace contacts{


class HXCPP_CLASS_ATTRIBUTES  B2PolyAndCircleContact_obj : public ::box2D::dynamics::contacts::B2Contact_obj{
	public:
		typedef ::box2D::dynamics::contacts::B2Contact_obj super;
		typedef B2PolyAndCircleContact_obj OBJ_;
		B2PolyAndCircleContact_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2PolyAndCircleContact_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2PolyAndCircleContact_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2PolyAndCircleContact"); }

		virtual Void reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB);

		virtual Void evaluate( );

		static ::box2D::dynamics::contacts::B2Contact create( Dynamic allocator);
		static Dynamic create_dyn();

		static Void destroy( ::box2D::dynamics::contacts::B2Contact contact,Dynamic allocator);
		static Dynamic destroy_dyn();

};

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts

#endif /* INCLUDED_box2D_dynamics_contacts_B2PolyAndCircleContact */ 
