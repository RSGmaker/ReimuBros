#include <hxcpp.h>

#ifndef INCLUDED_IntUtil
#include <IntUtil.h>
#endif
#ifndef INCLUDED_MD5
#include <MD5.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_ByteArray
#include <openfl/_v2/utils/ByteArray.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_IDataInput
#include <openfl/_v2/utils/IDataInput.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_IDataOutput
#include <openfl/_v2/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_openfl__v2_utils_IMemoryRange
#include <openfl/_v2/utils/IMemoryRange.h>
#endif

Void MD5_obj::__construct()
{
	return null();
}

//MD5_obj::~MD5_obj() { }

Dynamic MD5_obj::__CreateEmpty() { return  new MD5_obj; }
hx::ObjectPtr< MD5_obj > MD5_obj::__new()
{  hx::ObjectPtr< MD5_obj > result = new MD5_obj();
	result->__construct();
	return result;}

Dynamic MD5_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MD5_obj > result = new MD5_obj();
	result->__construct();
	return result;}

::openfl::_v2::utils::ByteArray MD5_obj::digest;

::String MD5_obj::hash( ::String s){
	HX_STACK_FRAME("MD5","hash",0x3240dd3e,"MD5.hash","MD5.hx",58,0x13e5cc80)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(61)
	::openfl::_v2::utils::ByteArray ba = ::openfl::_v2::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(ba,"ba");
	HX_STACK_LINE(62)
	ba->writeUTFBytes(s);
	HX_STACK_LINE(63)
	return ::MD5_obj::hashBinary(ba);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MD5_obj,hash,return )

::String MD5_obj::hashBytes( ::openfl::_v2::utils::ByteArray s){
	HX_STACK_FRAME("MD5","hashBytes",0x9f63da4d,"MD5.hashBytes","MD5.hx",67,0x13e5cc80)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(67)
	return ::MD5_obj::hashBinary(s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MD5_obj,hashBytes,return )

::String MD5_obj::hashBinary( ::openfl::_v2::utils::ByteArray s){
	HX_STACK_FRAME("MD5","hashBinary",0x9d978fdf,"MD5.hashBinary","MD5.hx",79,0x13e5cc80)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(81)
	int a = (int)1732584193;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(82)
	int b = (int)-271733879;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(83)
	int c = (int)-1732584194;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(84)
	int d = (int)271733878;		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(87)
	int aa;		HX_STACK_VAR(aa,"aa");
	HX_STACK_LINE(88)
	int bb;		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(89)
	int cc;		HX_STACK_VAR(cc,"cc");
	HX_STACK_LINE(90)
	int dd;		HX_STACK_VAR(dd,"dd");
	HX_STACK_LINE(95)
	Array< int > x = ::MD5_obj::createBlocks(s);		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(96)
	int len = x->length;		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(100)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(101)
	while((true)){
		HX_STACK_LINE(101)
		if ((!(((i < len))))){
			HX_STACK_LINE(101)
			break;
		}
		HX_STACK_LINE(103)
		aa = a;
		HX_STACK_LINE(104)
		bb = b;
		HX_STACK_LINE(105)
		cc = c;
		HX_STACK_LINE(106)
		dd = d;
		HX_STACK_LINE(109)
		int _g = ::MD5_obj::ff(a,b,c,d,x->__get(i),(int)7,(int)-680876936);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(109)
		a = _g;
		HX_STACK_LINE(110)
		int _g1 = ::MD5_obj::ff(d,a,b,c,x->__get((i + (int)1)),(int)12,(int)-389564586);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(110)
		d = _g1;
		HX_STACK_LINE(111)
		int _g2 = ::MD5_obj::ff(c,d,a,b,x->__get((i + (int)2)),(int)17,(int)606105819);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(111)
		c = _g2;
		HX_STACK_LINE(112)
		int _g3 = ::MD5_obj::ff(b,c,d,a,x->__get((i + (int)3)),(int)22,(int)-1044525330);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(112)
		b = _g3;
		HX_STACK_LINE(113)
		int _g4 = ::MD5_obj::ff(a,b,c,d,x->__get((i + (int)4)),(int)7,(int)-176418897);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(113)
		a = _g4;
		HX_STACK_LINE(114)
		int _g5 = ::MD5_obj::ff(d,a,b,c,x->__get((i + (int)5)),(int)12,(int)1200080426);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(114)
		d = _g5;
		HX_STACK_LINE(115)
		int _g6 = ::MD5_obj::ff(c,d,a,b,x->__get((i + (int)6)),(int)17,(int)-1473231341);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(115)
		c = _g6;
		HX_STACK_LINE(116)
		int _g7 = ::MD5_obj::ff(b,c,d,a,x->__get((i + (int)7)),(int)22,(int)-45705983);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(116)
		b = _g7;
		HX_STACK_LINE(117)
		int _g8 = ::MD5_obj::ff(a,b,c,d,x->__get((i + (int)8)),(int)7,(int)1770035416);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(117)
		a = _g8;
		HX_STACK_LINE(118)
		int _g9 = ::MD5_obj::ff(d,a,b,c,x->__get((i + (int)9)),(int)12,(int)-1958414417);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(118)
		d = _g9;
		HX_STACK_LINE(119)
		int _g10 = ::MD5_obj::ff(c,d,a,b,x->__get((i + (int)10)),(int)17,(int)-42063);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(119)
		c = _g10;
		HX_STACK_LINE(120)
		int _g11 = ::MD5_obj::ff(b,c,d,a,x->__get((i + (int)11)),(int)22,(int)-1990404162);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(120)
		b = _g11;
		HX_STACK_LINE(121)
		int _g12 = ::MD5_obj::ff(a,b,c,d,x->__get((i + (int)12)),(int)7,(int)1804603682);		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(121)
		a = _g12;
		HX_STACK_LINE(122)
		int _g13 = ::MD5_obj::ff(d,a,b,c,x->__get((i + (int)13)),(int)12,(int)-40341101);		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(122)
		d = _g13;
		HX_STACK_LINE(123)
		int _g14 = ::MD5_obj::ff(c,d,a,b,x->__get((i + (int)14)),(int)17,(int)-1502002290);		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(123)
		c = _g14;
		HX_STACK_LINE(124)
		int _g15 = ::MD5_obj::ff(b,c,d,a,x->__get((i + (int)15)),(int)22,(int)1236535329);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(124)
		b = _g15;
		HX_STACK_LINE(127)
		int _g16 = ::MD5_obj::gg(a,b,c,d,x->__get((i + (int)1)),(int)5,(int)-165796510);		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(127)
		a = _g16;
		HX_STACK_LINE(128)
		int _g17 = ::MD5_obj::gg(d,a,b,c,x->__get((i + (int)6)),(int)9,(int)-1069501632);		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(128)
		d = _g17;
		HX_STACK_LINE(129)
		int _g18 = ::MD5_obj::gg(c,d,a,b,x->__get((i + (int)11)),(int)14,(int)643717713);		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(129)
		c = _g18;
		HX_STACK_LINE(130)
		int _g19 = ::MD5_obj::gg(b,c,d,a,x->__get(i),(int)20,(int)-373897302);		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(130)
		b = _g19;
		HX_STACK_LINE(131)
		int _g20 = ::MD5_obj::gg(a,b,c,d,x->__get((i + (int)5)),(int)5,(int)-701558691);		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(131)
		a = _g20;
		HX_STACK_LINE(132)
		int _g21 = ::MD5_obj::gg(d,a,b,c,x->__get((i + (int)10)),(int)9,(int)38016083);		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(132)
		d = _g21;
		HX_STACK_LINE(133)
		int _g22 = ::MD5_obj::gg(c,d,a,b,x->__get((i + (int)15)),(int)14,(int)-660478335);		HX_STACK_VAR(_g22,"_g22");
		HX_STACK_LINE(133)
		c = _g22;
		HX_STACK_LINE(134)
		int _g23 = ::MD5_obj::gg(b,c,d,a,x->__get((i + (int)4)),(int)20,(int)-405537848);		HX_STACK_VAR(_g23,"_g23");
		HX_STACK_LINE(134)
		b = _g23;
		HX_STACK_LINE(135)
		int _g24 = ::MD5_obj::gg(a,b,c,d,x->__get((i + (int)9)),(int)5,(int)568446438);		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(135)
		a = _g24;
		HX_STACK_LINE(136)
		int _g25 = ::MD5_obj::gg(d,a,b,c,x->__get((i + (int)14)),(int)9,(int)-1019803690);		HX_STACK_VAR(_g25,"_g25");
		HX_STACK_LINE(136)
		d = _g25;
		HX_STACK_LINE(137)
		int _g26 = ::MD5_obj::gg(c,d,a,b,x->__get((i + (int)3)),(int)14,(int)-187363961);		HX_STACK_VAR(_g26,"_g26");
		HX_STACK_LINE(137)
		c = _g26;
		HX_STACK_LINE(138)
		int _g27 = ::MD5_obj::gg(b,c,d,a,x->__get((i + (int)8)),(int)20,(int)1163531501);		HX_STACK_VAR(_g27,"_g27");
		HX_STACK_LINE(138)
		b = _g27;
		HX_STACK_LINE(139)
		int _g28 = ::MD5_obj::gg(a,b,c,d,x->__get((i + (int)13)),(int)5,(int)-1444681467);		HX_STACK_VAR(_g28,"_g28");
		HX_STACK_LINE(139)
		a = _g28;
		HX_STACK_LINE(140)
		int _g29 = ::MD5_obj::gg(d,a,b,c,x->__get((i + (int)2)),(int)9,(int)-51403784);		HX_STACK_VAR(_g29,"_g29");
		HX_STACK_LINE(140)
		d = _g29;
		HX_STACK_LINE(141)
		int _g30 = ::MD5_obj::gg(c,d,a,b,x->__get((i + (int)7)),(int)14,(int)1735328473);		HX_STACK_VAR(_g30,"_g30");
		HX_STACK_LINE(141)
		c = _g30;
		HX_STACK_LINE(142)
		int _g31 = ::MD5_obj::gg(b,c,d,a,x->__get((i + (int)12)),(int)20,(int)-1926607734);		HX_STACK_VAR(_g31,"_g31");
		HX_STACK_LINE(142)
		b = _g31;
		HX_STACK_LINE(145)
		int _g32 = ::MD5_obj::hh(a,b,c,d,x->__get((i + (int)5)),(int)4,(int)-378558);		HX_STACK_VAR(_g32,"_g32");
		HX_STACK_LINE(145)
		a = _g32;
		HX_STACK_LINE(146)
		int _g33 = ::MD5_obj::hh(d,a,b,c,x->__get((i + (int)8)),(int)11,(int)-2022574463);		HX_STACK_VAR(_g33,"_g33");
		HX_STACK_LINE(146)
		d = _g33;
		HX_STACK_LINE(147)
		int _g34 = ::MD5_obj::hh(c,d,a,b,x->__get((i + (int)11)),(int)16,(int)1839030562);		HX_STACK_VAR(_g34,"_g34");
		HX_STACK_LINE(147)
		c = _g34;
		HX_STACK_LINE(148)
		int _g35 = ::MD5_obj::hh(b,c,d,a,x->__get((i + (int)14)),(int)23,(int)-35309556);		HX_STACK_VAR(_g35,"_g35");
		HX_STACK_LINE(148)
		b = _g35;
		HX_STACK_LINE(149)
		int _g36 = ::MD5_obj::hh(a,b,c,d,x->__get((i + (int)1)),(int)4,(int)-1530992060);		HX_STACK_VAR(_g36,"_g36");
		HX_STACK_LINE(149)
		a = _g36;
		HX_STACK_LINE(150)
		int _g37 = ::MD5_obj::hh(d,a,b,c,x->__get((i + (int)4)),(int)11,(int)1272893353);		HX_STACK_VAR(_g37,"_g37");
		HX_STACK_LINE(150)
		d = _g37;
		HX_STACK_LINE(151)
		int _g38 = ::MD5_obj::hh(c,d,a,b,x->__get((i + (int)7)),(int)16,(int)-155497632);		HX_STACK_VAR(_g38,"_g38");
		HX_STACK_LINE(151)
		c = _g38;
		HX_STACK_LINE(152)
		int _g39 = ::MD5_obj::hh(b,c,d,a,x->__get((i + (int)10)),(int)23,(int)-1094730640);		HX_STACK_VAR(_g39,"_g39");
		HX_STACK_LINE(152)
		b = _g39;
		HX_STACK_LINE(153)
		int _g40 = ::MD5_obj::hh(a,b,c,d,x->__get((i + (int)13)),(int)4,(int)681279174);		HX_STACK_VAR(_g40,"_g40");
		HX_STACK_LINE(153)
		a = _g40;
		HX_STACK_LINE(154)
		int _g41 = ::MD5_obj::hh(d,a,b,c,x->__get(i),(int)11,(int)-358537222);		HX_STACK_VAR(_g41,"_g41");
		HX_STACK_LINE(154)
		d = _g41;
		HX_STACK_LINE(155)
		int _g42 = ::MD5_obj::hh(c,d,a,b,x->__get((i + (int)3)),(int)16,(int)-722521979);		HX_STACK_VAR(_g42,"_g42");
		HX_STACK_LINE(155)
		c = _g42;
		HX_STACK_LINE(156)
		int _g43 = ::MD5_obj::hh(b,c,d,a,x->__get((i + (int)6)),(int)23,(int)76029189);		HX_STACK_VAR(_g43,"_g43");
		HX_STACK_LINE(156)
		b = _g43;
		HX_STACK_LINE(157)
		int _g44 = ::MD5_obj::hh(a,b,c,d,x->__get((i + (int)9)),(int)4,(int)-640364487);		HX_STACK_VAR(_g44,"_g44");
		HX_STACK_LINE(157)
		a = _g44;
		HX_STACK_LINE(158)
		int _g45 = ::MD5_obj::hh(d,a,b,c,x->__get((i + (int)12)),(int)11,(int)-421815835);		HX_STACK_VAR(_g45,"_g45");
		HX_STACK_LINE(158)
		d = _g45;
		HX_STACK_LINE(159)
		int _g46 = ::MD5_obj::hh(c,d,a,b,x->__get((i + (int)15)),(int)16,(int)530742520);		HX_STACK_VAR(_g46,"_g46");
		HX_STACK_LINE(159)
		c = _g46;
		HX_STACK_LINE(160)
		int _g47 = ::MD5_obj::hh(b,c,d,a,x->__get((i + (int)2)),(int)23,(int)-995338651);		HX_STACK_VAR(_g47,"_g47");
		HX_STACK_LINE(160)
		b = _g47;
		HX_STACK_LINE(163)
		int _g48 = ::MD5_obj::ii(a,b,c,d,x->__get(i),(int)6,(int)-198630844);		HX_STACK_VAR(_g48,"_g48");
		HX_STACK_LINE(163)
		a = _g48;
		HX_STACK_LINE(164)
		int _g49 = ::MD5_obj::ii(d,a,b,c,x->__get((i + (int)7)),(int)10,(int)1126891415);		HX_STACK_VAR(_g49,"_g49");
		HX_STACK_LINE(164)
		d = _g49;
		HX_STACK_LINE(165)
		int _g50 = ::MD5_obj::ii(c,d,a,b,x->__get((i + (int)14)),(int)15,(int)-1416354905);		HX_STACK_VAR(_g50,"_g50");
		HX_STACK_LINE(165)
		c = _g50;
		HX_STACK_LINE(166)
		int _g51 = ::MD5_obj::ii(b,c,d,a,x->__get((i + (int)5)),(int)21,(int)-57434055);		HX_STACK_VAR(_g51,"_g51");
		HX_STACK_LINE(166)
		b = _g51;
		HX_STACK_LINE(167)
		int _g52 = ::MD5_obj::ii(a,b,c,d,x->__get((i + (int)12)),(int)6,(int)1700485571);		HX_STACK_VAR(_g52,"_g52");
		HX_STACK_LINE(167)
		a = _g52;
		HX_STACK_LINE(168)
		int _g53 = ::MD5_obj::ii(d,a,b,c,x->__get((i + (int)3)),(int)10,(int)-1894986606);		HX_STACK_VAR(_g53,"_g53");
		HX_STACK_LINE(168)
		d = _g53;
		HX_STACK_LINE(169)
		int _g54 = ::MD5_obj::ii(c,d,a,b,x->__get((i + (int)10)),(int)15,(int)-1051523);		HX_STACK_VAR(_g54,"_g54");
		HX_STACK_LINE(169)
		c = _g54;
		HX_STACK_LINE(170)
		int _g55 = ::MD5_obj::ii(b,c,d,a,x->__get((i + (int)1)),(int)21,(int)-2054922799);		HX_STACK_VAR(_g55,"_g55");
		HX_STACK_LINE(170)
		b = _g55;
		HX_STACK_LINE(171)
		int _g56 = ::MD5_obj::ii(a,b,c,d,x->__get((i + (int)8)),(int)6,(int)1873313359);		HX_STACK_VAR(_g56,"_g56");
		HX_STACK_LINE(171)
		a = _g56;
		HX_STACK_LINE(172)
		int _g57 = ::MD5_obj::ii(d,a,b,c,x->__get((i + (int)15)),(int)10,(int)-30611744);		HX_STACK_VAR(_g57,"_g57");
		HX_STACK_LINE(172)
		d = _g57;
		HX_STACK_LINE(173)
		int _g58 = ::MD5_obj::ii(c,d,a,b,x->__get((i + (int)6)),(int)15,(int)-1560198380);		HX_STACK_VAR(_g58,"_g58");
		HX_STACK_LINE(173)
		c = _g58;
		HX_STACK_LINE(174)
		int _g59 = ::MD5_obj::ii(b,c,d,a,x->__get((i + (int)13)),(int)21,(int)1309151649);		HX_STACK_VAR(_g59,"_g59");
		HX_STACK_LINE(174)
		b = _g59;
		HX_STACK_LINE(175)
		int _g60 = ::MD5_obj::ii(a,b,c,d,x->__get((i + (int)4)),(int)6,(int)-145523070);		HX_STACK_VAR(_g60,"_g60");
		HX_STACK_LINE(175)
		a = _g60;
		HX_STACK_LINE(176)
		int _g61 = ::MD5_obj::ii(d,a,b,c,x->__get((i + (int)11)),(int)10,(int)-1120210379);		HX_STACK_VAR(_g61,"_g61");
		HX_STACK_LINE(176)
		d = _g61;
		HX_STACK_LINE(177)
		int _g62 = ::MD5_obj::ii(c,d,a,b,x->__get((i + (int)2)),(int)15,(int)718787259);		HX_STACK_VAR(_g62,"_g62");
		HX_STACK_LINE(177)
		c = _g62;
		HX_STACK_LINE(178)
		int _g63 = ::MD5_obj::ii(b,c,d,a,x->__get((i + (int)9)),(int)21,(int)-343485551);		HX_STACK_VAR(_g63,"_g63");
		HX_STACK_LINE(178)
		b = _g63;
		HX_STACK_LINE(180)
		hx::AddEq(a,aa);
		HX_STACK_LINE(181)
		hx::AddEq(b,bb);
		HX_STACK_LINE(182)
		hx::AddEq(c,cc);
		HX_STACK_LINE(183)
		hx::AddEq(d,dd);
		HX_STACK_LINE(185)
		hx::AddEq(i,(int)16);
	}
	HX_STACK_LINE(187)
	::openfl::_v2::utils::ByteArray _g64 = ::openfl::_v2::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(_g64,"_g64");
	HX_STACK_LINE(187)
	::MD5_obj::digest = _g64;
	HX_STACK_LINE(188)
	::MD5_obj::digest->writeInt(a);
	HX_STACK_LINE(189)
	::MD5_obj::digest->writeInt(b);
	HX_STACK_LINE(190)
	::MD5_obj::digest->writeInt(c);
	HX_STACK_LINE(191)
	::MD5_obj::digest->writeInt(d);
	HX_STACK_LINE(196)
	::MD5_obj::digest->position = (int)0;
	HX_STACK_LINE(198)
	::String _g65 = ::IntUtil_obj::toHex(a,null());		HX_STACK_VAR(_g65,"_g65");
	HX_STACK_LINE(198)
	::String _g66 = ::IntUtil_obj::toHex(b,null());		HX_STACK_VAR(_g66,"_g66");
	HX_STACK_LINE(198)
	::String _g67 = (_g65 + _g66);		HX_STACK_VAR(_g67,"_g67");
	HX_STACK_LINE(198)
	::String _g68 = ::IntUtil_obj::toHex(c,null());		HX_STACK_VAR(_g68,"_g68");
	HX_STACK_LINE(198)
	::String _g69 = (_g67 + _g68);		HX_STACK_VAR(_g69,"_g69");
	HX_STACK_LINE(198)
	::String _g70 = ::IntUtil_obj::toHex(d,null());		HX_STACK_VAR(_g70,"_g70");
	HX_STACK_LINE(198)
	return (_g69 + _g70);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MD5_obj,hashBinary,return )

int MD5_obj::f( int x,int y,int z){
	HX_STACK_FRAME("MD5","f",0x82f58cf6,"MD5.f","MD5.hx",205,0x13e5cc80)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(z,"z")
	HX_STACK_LINE(205)
	return (int((int(x) & int(y))) | int((int(~(int)(x)) & int(z))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(MD5_obj,f,return )

int MD5_obj::g( int x,int y,int z){
	HX_STACK_FRAME("MD5","g",0x82f58cf7,"MD5.g","MD5.hx",212,0x13e5cc80)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(z,"z")
	HX_STACK_LINE(212)
	return (int((int(x) & int(z))) | int((int(y) & int(~(int)(z)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(MD5_obj,g,return )

int MD5_obj::h( int x,int y,int z){
	HX_STACK_FRAME("MD5","h",0x82f58cf8,"MD5.h","MD5.hx",219,0x13e5cc80)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(z,"z")
	HX_STACK_LINE(219)
	return (int((int(x) ^ int(y))) ^ int(z));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(MD5_obj,h,return )

int MD5_obj::i( int x,int y,int z){
	HX_STACK_FRAME("MD5","i",0x82f58cf9,"MD5.i","MD5.hx",226,0x13e5cc80)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(z,"z")
	HX_STACK_LINE(226)
	return (int(y) ^ int(((int(x) | int(~(int)(z))))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(MD5_obj,i,return )

int MD5_obj::transform( Dynamic func,int a,int b,int c,int d,int x,int s,int t){
	HX_STACK_FRAME("MD5","transform",0xf2bfc9fc,"MD5.transform","MD5.hx",235,0x13e5cc80)
	HX_STACK_ARG(func,"func")
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(d,"d")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(236)
	Dynamic _g = func(b,c,d);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(236)
	Dynamic _g1 = (a + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(236)
	Dynamic _g2 = (_g1 + x);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(236)
	int tmp = (_g2 + t);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(237)
	int _g3 = ::IntUtil_obj::rol(tmp,s);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(237)
	return (_g3 + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(MD5_obj,transform,return )

int MD5_obj::ff( int a,int b,int c,int d,int x,int s,int t){
	HX_STACK_FRAME("MD5","ff",0x13e5cab0,"MD5.ff","MD5.hx",244,0x13e5cc80)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(d,"d")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(244)
	return ::MD5_obj::transform(::MD5_obj::f_dyn(),a,b,c,d,x,s,t);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(MD5_obj,ff,return )

int MD5_obj::gg( int a,int b,int c,int d,int x,int s,int t){
	HX_STACK_FRAME("MD5","gg",0x13e5cb90,"MD5.gg","MD5.hx",251,0x13e5cc80)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(d,"d")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(251)
	return ::MD5_obj::transform(::MD5_obj::g_dyn(),a,b,c,d,x,s,t);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(MD5_obj,gg,return )

int MD5_obj::hh( int a,int b,int c,int d,int x,int s,int t){
	HX_STACK_FRAME("MD5","hh",0x13e5cc70,"MD5.hh","MD5.hx",258,0x13e5cc80)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(d,"d")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(258)
	return ::MD5_obj::transform(::MD5_obj::h_dyn(),a,b,c,d,x,s,t);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(MD5_obj,hh,return )

int MD5_obj::ii( int a,int b,int c,int d,int x,int s,int t){
	HX_STACK_FRAME("MD5","ii",0x13e5cd50,"MD5.ii","MD5.hx",265,0x13e5cc80)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(d,"d")
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(265)
	return ::MD5_obj::transform(::MD5_obj::i_dyn(),a,b,c,d,x,s,t);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(MD5_obj,ii,return )

Array< int > MD5_obj::createBlocks( ::openfl::_v2::utils::ByteArray s){
	HX_STACK_FRAME("MD5","createBlocks",0x1d0b0c12,"MD5.createBlocks","MD5.hx",277,0x13e5cc80)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(278)
	Array< int > blocks = Array_obj< int >::__new();		HX_STACK_VAR(blocks,"blocks");
	HX_STACK_LINE(279)
	int len = (s->length * (int)8);		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(280)
	int mask = (int)255;		HX_STACK_VAR(mask,"mask");
	HX_STACK_LINE(282)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(283)
	while((true)){
		HX_STACK_LINE(283)
		if ((!(((i < len))))){
			HX_STACK_LINE(283)
			break;
		}
		HX_STACK_LINE(287)
		int _g = ::Math_obj::floor((Float(i) / Float((int)8)));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(287)
		int _g1 = s->__get(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(287)
		int _g2 = (int(_g1) & int(mask));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(287)
		hx::OrEq(blocks[(int(i) >> int((int)5))],(int(_g2) << int(hx::Mod(i,(int)32))));
		HX_STACK_LINE(290)
		hx::AddEq(i,(int)8);
	}
	HX_STACK_LINE(294)
	hx::OrEq(blocks[(int(len) >> int((int)5))],(int((int)128) << int(hx::Mod(len,(int)32))));
	HX_STACK_LINE(295)
	blocks[(((int(hx::UShr((len + (int)64),(int)9)) << int((int)4))) + (int)14)] = len;
	HX_STACK_LINE(296)
	return blocks;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MD5_obj,createBlocks,return )


MD5_obj::MD5_obj()
{
}

Dynamic MD5_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"f") ) { return f_dyn(); }
		if (HX_FIELD_EQ(inName,"g") ) { return g_dyn(); }
		if (HX_FIELD_EQ(inName,"h") ) { return h_dyn(); }
		if (HX_FIELD_EQ(inName,"i") ) { return i_dyn(); }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"ff") ) { return ff_dyn(); }
		if (HX_FIELD_EQ(inName,"gg") ) { return gg_dyn(); }
		if (HX_FIELD_EQ(inName,"hh") ) { return hh_dyn(); }
		if (HX_FIELD_EQ(inName,"ii") ) { return ii_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"hash") ) { return hash_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"digest") ) { return digest; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hashBytes") ) { return hashBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hashBinary") ) { return hashBinary_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"createBlocks") ) { return createBlocks_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MD5_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"digest") ) { digest=inValue.Cast< ::openfl::_v2::utils::ByteArray >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MD5_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("digest"),
	HX_CSTRING("hash"),
	HX_CSTRING("hashBytes"),
	HX_CSTRING("hashBinary"),
	HX_CSTRING("f"),
	HX_CSTRING("g"),
	HX_CSTRING("h"),
	HX_CSTRING("i"),
	HX_CSTRING("transform"),
	HX_CSTRING("ff"),
	HX_CSTRING("gg"),
	HX_CSTRING("hh"),
	HX_CSTRING("ii"),
	HX_CSTRING("createBlocks"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MD5_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(MD5_obj::digest,"digest");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MD5_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(MD5_obj::digest,"digest");
};

#endif

Class MD5_obj::__mClass;

void MD5_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("MD5"), hx::TCanCast< MD5_obj> ,sStaticFields,sMemberFields,
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

void MD5_obj::__boot()
{
}

