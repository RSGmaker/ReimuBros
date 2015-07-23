#ifndef INCLUDED_TypeofRound
#define INCLUDED_TypeofRound

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(TypeofRound)


class TypeofRound_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TypeofRound_obj OBJ_;

	public:
		TypeofRound_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("TypeofRound"); }
		::String __ToString() const { return HX_CSTRING("TypeofRound.") + tag; }

		static ::TypeofRound Cirno;
		static inline ::TypeofRound Cirno_dyn() { return Cirno; }
		static ::TypeofRound FireCirno;
		static inline ::TypeofRound FireCirno_dyn() { return FireCirno; }
		static ::TypeofRound Normal;
		static inline ::TypeofRound Normal_dyn() { return Normal; }
		static ::TypeofRound Nue;
		static inline ::TypeofRound Nue_dyn() { return Nue; }
		static ::TypeofRound Rumia;
		static inline ::TypeofRound Rumia_dyn() { return Rumia; }
		static ::TypeofRound Seija;
		static inline ::TypeofRound Seija_dyn() { return Seija; }
		static ::TypeofRound Table;
		static inline ::TypeofRound Table_dyn() { return Table; }
		static ::TypeofRound Yukari;
		static inline ::TypeofRound Yukari_dyn() { return Yukari; }
};


#endif /* INCLUDED_TypeofRound */ 
