#include <hxcpp.h>

#ifndef INCLUDED_MersenneTwister
#include <MersenneTwister.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void MersenneTwister_obj::__construct()
{
HX_STACK_FRAME("MersenneTwister","new",0xc7039cad,"MersenneTwister.new","MersenneTwister.hx",53,0xd0ad5763)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(58)
	this->LOWER_MASK = (int)2147483647;
	HX_STACK_LINE(57)
	this->UPPER_MASK = (int)-2147483648;
	HX_STACK_LINE(56)
	this->MATRIX_A = (int)-1727483681;
	HX_STACK_LINE(55)
	this->M = (int)397;
	HX_STACK_LINE(54)
	this->N = (int)624;
	HX_STACK_LINE(70)
	this->seed = (int)0;
}
;
	return null();
}

//MersenneTwister_obj::~MersenneTwister_obj() { }

Dynamic MersenneTwister_obj::__CreateEmpty() { return  new MersenneTwister_obj; }
hx::ObjectPtr< MersenneTwister_obj > MersenneTwister_obj::__new()
{  hx::ObjectPtr< MersenneTwister_obj > result = new MersenneTwister_obj();
	result->__construct();
	return result;}

Dynamic MersenneTwister_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MersenneTwister_obj > result = new MersenneTwister_obj();
	result->__construct();
	return result;}

Array< int > MersenneTwister_obj::twist( hx::Null< int >  __o_TTseed,int TTreturnLength,int TTmaxSize){
int TTseed = __o_TTseed.Default(0);
	HX_STACK_FRAME("MersenneTwister","twist",0xc4e8f934,"MersenneTwister.twist","MersenneTwister.hx",78,0xd0ad5763)
	HX_STACK_THIS(this)
	HX_STACK_ARG(TTseed,"TTseed")
	HX_STACK_ARG(TTreturnLength,"TTreturnLength")
	HX_STACK_ARG(TTmaxSize,"TTmaxSize")
{
		struct _Function_1_1{
			inline static Float Block( int &TTseed){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","MersenneTwister.hx",79,0xd0ad5763)
				{
					HX_STACK_LINE(79)
					int _int = TTseed;		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(79)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(79)
		if (((_Function_1_1::Block(TTseed) != (int)0))){
			HX_STACK_LINE(81)
			this->seed = TTseed;
		}
		HX_STACK_LINE(83)
		this->returnLength = TTreturnLength;
		HX_STACK_LINE(84)
		this->maxSize = TTmaxSize;
		HX_STACK_LINE(85)
		this->mt = Array_obj< int >::__new();
		HX_STACK_LINE(87)
		this->returnArray = Array_obj< int >::__new();
		HX_STACK_LINE(89)
		this->mti = (this->N + (int)1);
		HX_STACK_LINE(90)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(92)
		Array< int > initArray = Array_obj< int >::__new().Add((int)291).Add((int)564).Add((int)837).Add((int)1110);		HX_STACK_VAR(initArray,"initArray");
		HX_STACK_LINE(93)
		this->init_by_array(initArray,initArray->length);
		HX_STACK_LINE(94)
		i = (int)0;
		HX_STACK_LINE(98)
		while((true)){
			HX_STACK_LINE(98)
			if ((!(((i < this->returnLength))))){
				HX_STACK_LINE(98)
				break;
			}
			HX_STACK_LINE(100)
			{
				HX_STACK_LINE(100)
				int a = this->genrand_int32();		HX_STACK_VAR(a,"a");
				struct _Function_3_1{
					inline static Float Block( int &a){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","MersenneTwister.hx",100,0xd0ad5763)
						{
							HX_STACK_LINE(100)
							int _int = a;		HX_STACK_VAR(_int,"int");
							HX_STACK_LINE(100)
							return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
						}
						return null();
					}
				};
				struct _Function_3_2{
					inline static Float Block( hx::ObjectPtr< ::MersenneTwister_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","MersenneTwister.hx",100,0xd0ad5763)
						{
							HX_STACK_LINE(100)
							int _int = __this->maxSize;		HX_STACK_VAR(_int,"int");
							HX_STACK_LINE(100)
							return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
						}
						return null();
					}
				};
				HX_STACK_LINE(100)
				this->returnArray[i] = ::Std_obj::_int(hx::Mod(_Function_3_1::Block(a),_Function_3_2::Block(this)));
			}
			HX_STACK_LINE(101)
			(i)++;
		}
		HX_STACK_LINE(103)
		int _g = this->genrand_int32();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(103)
		this->seed = _g;
		HX_STACK_LINE(113)
		return this->returnArray;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(MersenneTwister_obj,twist,return )

Void MersenneTwister_obj::init_genrand( int TTseed){
{
		HX_STACK_FRAME("MersenneTwister","init_genrand",0x5d003cd9,"MersenneTwister.init_genrand","MersenneTwister.hx",119,0xd0ad5763)
		HX_STACK_THIS(this)
		HX_STACK_ARG(TTseed,"TTseed")
		HX_STACK_LINE(120)
		this->mt[(int)0] = (int(TTseed) & int((int)-1));
		HX_STACK_LINE(121)
		this->mti = (int)1;
		HX_STACK_LINE(122)
		while((true)){
			HX_STACK_LINE(122)
			if ((!(((this->mti < this->N))))){
				HX_STACK_LINE(122)
				break;
			}
			HX_STACK_LINE(124)
			this->mt[this->mti] = (((int)1812433253 * ((int(this->mt->__get((this->mti - (int)1))) ^ int((int(this->mt->__get((this->mti - (int)1))) >> int((int)30)))))) + this->mti);
			HX_STACK_LINE(125)
			this->mt[this->mti] = (int(this->mt->__get(this->mti)) & int((int)-1));
			HX_STACK_LINE(126)
			(this->mti)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MersenneTwister_obj,init_genrand,(void))

Void MersenneTwister_obj::init_by_array( Array< int > TTseedArray,int TTseedArrayLength){
{
		HX_STACK_FRAME("MersenneTwister","init_by_array",0x66fb6ecd,"MersenneTwister.init_by_array","MersenneTwister.hx",142,0xd0ad5763)
		HX_STACK_THIS(this)
		HX_STACK_ARG(TTseedArray,"TTseedArray")
		HX_STACK_ARG(TTseedArrayLength,"TTseedArrayLength")
		HX_STACK_LINE(143)
		int i = (int)1;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(144)
		int j = (int)0;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(145)
		this->init_genrand(this->seed);
		HX_STACK_LINE(147)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(147)
		if (((this->N > TTseedArrayLength))){
			HX_STACK_LINE(147)
			k = this->N;
		}
		else{
			HX_STACK_LINE(147)
			k = TTseedArrayLength;
		}
		HX_STACK_LINE(148)
		while((true)){
			HX_STACK_LINE(148)
			if ((!(((k > (int)0))))){
				HX_STACK_LINE(148)
				break;
			}
			HX_STACK_LINE(150)
			this->mt[i] = ((((int(this->mt->__get(i)) ^ int((((int(this->mt->__get((i - (int)1))) ^ int((int(this->mt->__get((i - (int)1))) >> int((int)30))))) * (int)1664525)))) + TTseedArray->__get(j)) + j);
			HX_STACK_LINE(151)
			this->mt[i] = (int(this->mt->__get(i)) & int((int)-1));
			HX_STACK_LINE(152)
			(i)++;
			HX_STACK_LINE(153)
			(j)++;
			HX_STACK_LINE(154)
			if (((i >= this->N))){
				HX_STACK_LINE(155)
				this->mt[(int)0] = this->mt->__get((this->N - (int)1));
				HX_STACK_LINE(156)
				i = (int)1;
			}
			HX_STACK_LINE(158)
			if (((j >= TTseedArrayLength))){
				HX_STACK_LINE(158)
				j = (int)0;
			}
			HX_STACK_LINE(159)
			(k)--;
		}
		HX_STACK_LINE(161)
		k = (this->N - (int)1);
		HX_STACK_LINE(162)
		while((true)){
			HX_STACK_LINE(162)
			if ((!(((k > (int)0))))){
				HX_STACK_LINE(162)
				break;
			}
			HX_STACK_LINE(164)
			this->mt[i] = (((int(this->mt->__get(i)) ^ int((((int(this->mt->__get((i - (int)1))) ^ int((int(this->mt->__get((i - (int)1))) >> int((int)30))))) * (int)1566083941)))) - i);
			HX_STACK_LINE(165)
			this->mt[i] = (int(this->mt->__get(i)) & int((int)-1));
			HX_STACK_LINE(166)
			(i)++;
			HX_STACK_LINE(167)
			if (((i >= this->N))){
				HX_STACK_LINE(168)
				this->mt[(int)0] = this->mt->__get((this->N - (int)1));
				HX_STACK_LINE(169)
				i = (int)1;
			}
			HX_STACK_LINE(171)
			(k)--;
		}
		HX_STACK_LINE(195)
		this->mt[(int)0] = (int)-2147483648;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MersenneTwister_obj,init_by_array,(void))

int MersenneTwister_obj::genrand_int32( ){
	HX_STACK_FRAME("MersenneTwister","genrand_int32",0x13115511,"MersenneTwister.genrand_int32","MersenneTwister.hx",199,0xd0ad5763)
	HX_STACK_THIS(this)
	HX_STACK_LINE(200)
	int y;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(201)
	Array< int > mag01 = Array_obj< int >::__new().Add((int)0).Add(this->MATRIX_A);		HX_STACK_VAR(mag01,"mag01");
	HX_STACK_LINE(204)
	if (((this->mti >= this->N))){
		HX_STACK_LINE(205)
		int kk;		HX_STACK_VAR(kk,"kk");
		HX_STACK_LINE(207)
		if (((this->mti == (this->N + (int)1)))){
			HX_STACK_LINE(208)
			this->init_genrand((int)5489);
		}
		HX_STACK_LINE(209)
		kk = (int)0;
		HX_STACK_LINE(210)
		while((true)){
			HX_STACK_LINE(210)
			if ((!(((kk < (this->N - this->M)))))){
				HX_STACK_LINE(210)
				break;
			}
			HX_STACK_LINE(212)
			y = (int((int(this->mt->__get(kk)) & int(this->UPPER_MASK))) | int((int(this->mt->__get((kk + (int)1))) & int(this->LOWER_MASK))));
			HX_STACK_LINE(213)
			this->mt[kk] = (int((int(this->mt->__get((kk + this->M))) ^ int((int(y) >> int((int)1))))) ^ int(mag01->__get((int(y) & int((int)1)))));
			HX_STACK_LINE(214)
			(kk)++;
		}
		HX_STACK_LINE(216)
		while((true)){
			HX_STACK_LINE(216)
			if ((!(((kk < (this->N - (int)1)))))){
				HX_STACK_LINE(216)
				break;
			}
			HX_STACK_LINE(218)
			y = (int((int(this->mt->__get(kk)) & int(this->UPPER_MASK))) | int((int(this->mt->__get((kk + (int)1))) & int(this->LOWER_MASK))));
			HX_STACK_LINE(219)
			this->mt[kk] = (int((int(this->mt->__get((kk + ((this->M - this->N))))) ^ int((int(y) >> int((int)1))))) ^ int(mag01->__get((int(y) & int((int)1)))));
			HX_STACK_LINE(220)
			(kk)++;
		}
		HX_STACK_LINE(231)
		y = (int((int(this->mt->__get((this->N - (int)1))) & int(this->UPPER_MASK))) | int((int(this->mt->__get((int)0)) & int(this->LOWER_MASK))));
		HX_STACK_LINE(232)
		this->mt[(this->N - (int)1)] = (int((int(this->mt->__get((this->M - (int)1))) ^ int((int(y) >> int((int)1))))) ^ int(mag01->__get((int(y) & int((int)1)))));
		HX_STACK_LINE(234)
		this->mti = (int)0;
	}
	HX_STACK_LINE(237)
	int _g = (this->mti)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(237)
	int _g1 = this->mt->__get(_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(237)
	y = _g1;
	HX_STACK_LINE(240)
	y = (int(y) ^ int((int(y) >> int((int)11))));
	HX_STACK_LINE(241)
	y = (int(y) ^ int((int((int(y) << int((int)7))) & int((int)-1658038656))));
	HX_STACK_LINE(242)
	y = (int(y) ^ int((int((int(y) << int((int)15))) & int((int)-272236544))));
	HX_STACK_LINE(243)
	y = (int(y) ^ int((int(y) >> int((int)18))));
	HX_STACK_LINE(245)
	return y;
}


HX_DEFINE_DYNAMIC_FUNC0(MersenneTwister_obj,genrand_int32,return )

int MersenneTwister_obj::genrand_int31( ){
	HX_STACK_FRAME("MersenneTwister","genrand_int31",0x13115510,"MersenneTwister.genrand_int31","MersenneTwister.hx",250,0xd0ad5763)
	HX_STACK_THIS(this)
	HX_STACK_LINE(250)
	int a = this->genrand_int32();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(250)
	return (int(a) >> int((int)1));
}


HX_DEFINE_DYNAMIC_FUNC0(MersenneTwister_obj,genrand_int31,return )


MersenneTwister_obj::MersenneTwister_obj()
{
}

void MersenneTwister_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MersenneTwister);
	HX_MARK_MEMBER_NAME(N,"N");
	HX_MARK_MEMBER_NAME(M,"M");
	HX_MARK_MEMBER_NAME(MATRIX_A,"MATRIX_A");
	HX_MARK_MEMBER_NAME(UPPER_MASK,"UPPER_MASK");
	HX_MARK_MEMBER_NAME(LOWER_MASK,"LOWER_MASK");
	HX_MARK_MEMBER_NAME(mt,"mt");
	HX_MARK_MEMBER_NAME(mti,"mti");
	HX_MARK_MEMBER_NAME(seed,"seed");
	HX_MARK_MEMBER_NAME(returnLength,"returnLength");
	HX_MARK_MEMBER_NAME(maxSize,"maxSize");
	HX_MARK_MEMBER_NAME(returnArray,"returnArray");
	HX_MARK_END_CLASS();
}

void MersenneTwister_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(N,"N");
	HX_VISIT_MEMBER_NAME(M,"M");
	HX_VISIT_MEMBER_NAME(MATRIX_A,"MATRIX_A");
	HX_VISIT_MEMBER_NAME(UPPER_MASK,"UPPER_MASK");
	HX_VISIT_MEMBER_NAME(LOWER_MASK,"LOWER_MASK");
	HX_VISIT_MEMBER_NAME(mt,"mt");
	HX_VISIT_MEMBER_NAME(mti,"mti");
	HX_VISIT_MEMBER_NAME(seed,"seed");
	HX_VISIT_MEMBER_NAME(returnLength,"returnLength");
	HX_VISIT_MEMBER_NAME(maxSize,"maxSize");
	HX_VISIT_MEMBER_NAME(returnArray,"returnArray");
}

Dynamic MersenneTwister_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"N") ) { return N; }
		if (HX_FIELD_EQ(inName,"M") ) { return M; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"mt") ) { return mt; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"mti") ) { return mti; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"seed") ) { return seed; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"twist") ) { return twist_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"maxSize") ) { return maxSize; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MATRIX_A") ) { return MATRIX_A; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"UPPER_MASK") ) { return UPPER_MASK; }
		if (HX_FIELD_EQ(inName,"LOWER_MASK") ) { return LOWER_MASK; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"returnArray") ) { return returnArray; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"returnLength") ) { return returnLength; }
		if (HX_FIELD_EQ(inName,"init_genrand") ) { return init_genrand_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"init_by_array") ) { return init_by_array_dyn(); }
		if (HX_FIELD_EQ(inName,"genrand_int32") ) { return genrand_int32_dyn(); }
		if (HX_FIELD_EQ(inName,"genrand_int31") ) { return genrand_int31_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MersenneTwister_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"N") ) { N=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"M") ) { M=inValue.Cast< int >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"mt") ) { mt=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"mti") ) { mti=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"seed") ) { seed=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"maxSize") ) { maxSize=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MATRIX_A") ) { MATRIX_A=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"UPPER_MASK") ) { UPPER_MASK=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LOWER_MASK") ) { LOWER_MASK=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"returnArray") ) { returnArray=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"returnLength") ) { returnLength=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MersenneTwister_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("N"));
	outFields->push(HX_CSTRING("M"));
	outFields->push(HX_CSTRING("MATRIX_A"));
	outFields->push(HX_CSTRING("UPPER_MASK"));
	outFields->push(HX_CSTRING("LOWER_MASK"));
	outFields->push(HX_CSTRING("mt"));
	outFields->push(HX_CSTRING("mti"));
	outFields->push(HX_CSTRING("seed"));
	outFields->push(HX_CSTRING("returnLength"));
	outFields->push(HX_CSTRING("maxSize"));
	outFields->push(HX_CSTRING("returnArray"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(MersenneTwister_obj,N),HX_CSTRING("N")},
	{hx::fsInt,(int)offsetof(MersenneTwister_obj,M),HX_CSTRING("M")},
	{hx::fsInt,(int)offsetof(MersenneTwister_obj,MATRIX_A),HX_CSTRING("MATRIX_A")},
	{hx::fsInt,(int)offsetof(MersenneTwister_obj,UPPER_MASK),HX_CSTRING("UPPER_MASK")},
	{hx::fsInt,(int)offsetof(MersenneTwister_obj,LOWER_MASK),HX_CSTRING("LOWER_MASK")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MersenneTwister_obj,mt),HX_CSTRING("mt")},
	{hx::fsInt,(int)offsetof(MersenneTwister_obj,mti),HX_CSTRING("mti")},
	{hx::fsInt,(int)offsetof(MersenneTwister_obj,seed),HX_CSTRING("seed")},
	{hx::fsInt,(int)offsetof(MersenneTwister_obj,returnLength),HX_CSTRING("returnLength")},
	{hx::fsInt,(int)offsetof(MersenneTwister_obj,maxSize),HX_CSTRING("maxSize")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MersenneTwister_obj,returnArray),HX_CSTRING("returnArray")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("N"),
	HX_CSTRING("M"),
	HX_CSTRING("MATRIX_A"),
	HX_CSTRING("UPPER_MASK"),
	HX_CSTRING("LOWER_MASK"),
	HX_CSTRING("mt"),
	HX_CSTRING("mti"),
	HX_CSTRING("seed"),
	HX_CSTRING("returnLength"),
	HX_CSTRING("maxSize"),
	HX_CSTRING("returnArray"),
	HX_CSTRING("twist"),
	HX_CSTRING("init_genrand"),
	HX_CSTRING("init_by_array"),
	HX_CSTRING("genrand_int32"),
	HX_CSTRING("genrand_int31"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MersenneTwister_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MersenneTwister_obj::__mClass,"__mClass");
};

#endif

Class MersenneTwister_obj::__mClass;

void MersenneTwister_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("MersenneTwister"), hx::TCanCast< MersenneTwister_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void MersenneTwister_obj::__boot()
{
}

