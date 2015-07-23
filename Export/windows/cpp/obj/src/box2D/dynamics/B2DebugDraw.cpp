#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Color
#include <box2D/common/B2Color.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2DebugDraw
#include <box2D/dynamics/B2DebugDraw.h>
#endif
#ifndef INCLUDED_openfl__v2_display_CapsStyle
#include <openfl/_v2/display/CapsStyle.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Graphics
#include <openfl/_v2/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_JointStyle
#include <openfl/_v2/display/JointStyle.h>
#endif
#ifndef INCLUDED_openfl__v2_display_LineScaleMode
#include <openfl/_v2/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
namespace box2D{
namespace dynamics{

Void B2DebugDraw_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","new",0x69b3ce30,"box2D.dynamics.B2DebugDraw.new","box2D/dynamics/B2DebugDraw.hx",35,0x7faf8720)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(37)
	this->m_drawScale = 1.0;
	HX_STACK_LINE(39)
	this->m_lineThickness = 1.0;
	HX_STACK_LINE(40)
	this->m_alpha = 1.0;
	HX_STACK_LINE(41)
	this->m_fillAlpha = 1.0;
	HX_STACK_LINE(42)
	this->m_xformScale = 1.0;
	HX_STACK_LINE(45)
	this->m_drawFlags = (int)0;
}
;
	return null();
}

//B2DebugDraw_obj::~B2DebugDraw_obj() { }

Dynamic B2DebugDraw_obj::__CreateEmpty() { return  new B2DebugDraw_obj; }
hx::ObjectPtr< B2DebugDraw_obj > B2DebugDraw_obj::__new()
{  hx::ObjectPtr< B2DebugDraw_obj > result = new B2DebugDraw_obj();
	result->__construct();
	return result;}

Dynamic B2DebugDraw_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DebugDraw_obj > result = new B2DebugDraw_obj();
	result->__construct();
	return result;}

Void B2DebugDraw_obj::setFlags( int flags){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","setFlags",0xc3868475,"box2D.dynamics.B2DebugDraw.setFlags","box2D/dynamics/B2DebugDraw.hx",70,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flags,"flags")
		HX_STACK_LINE(70)
		this->m_drawFlags = flags;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setFlags,(void))

int B2DebugDraw_obj::getFlags( ){
	HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","getFlags",0x15292b01,"box2D.dynamics.B2DebugDraw.getFlags","box2D/dynamics/B2DebugDraw.hx",77,0x7faf8720)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	return this->m_drawFlags;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getFlags,return )

Void B2DebugDraw_obj::appendFlags( int flags){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","appendFlags",0x984d10dd,"box2D.dynamics.B2DebugDraw.appendFlags","box2D/dynamics/B2DebugDraw.hx",84,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flags,"flags")
		HX_STACK_LINE(84)
		hx::OrEq(this->m_drawFlags,flags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,appendFlags,(void))

Void B2DebugDraw_obj::clearFlags( int flags){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","clearFlags",0x3bdcc6aa,"box2D.dynamics.B2DebugDraw.clearFlags","box2D/dynamics/B2DebugDraw.hx",91,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flags,"flags")
		HX_STACK_LINE(91)
		hx::AndEq(this->m_drawFlags,~(int)(flags));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,clearFlags,(void))

Void B2DebugDraw_obj::setSprite( ::openfl::_v2::display::Sprite sprite){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","setSprite",0xdda98b17,"box2D.dynamics.B2DebugDraw.setSprite","box2D/dynamics/B2DebugDraw.hx",98,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(sprite,"sprite")
		HX_STACK_LINE(98)
		this->m_sprite = sprite;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setSprite,(void))

::openfl::_v2::display::Sprite B2DebugDraw_obj::getSprite( ){
	HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","getSprite",0xfa589f0b,"box2D.dynamics.B2DebugDraw.getSprite","box2D/dynamics/B2DebugDraw.hx",105,0x7faf8720)
	HX_STACK_THIS(this)
	HX_STACK_LINE(105)
	return this->m_sprite;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getSprite,return )

Void B2DebugDraw_obj::setDrawScale( Float drawScale){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","setDrawScale",0x2ce38c14,"box2D.dynamics.B2DebugDraw.setDrawScale","box2D/dynamics/B2DebugDraw.hx",112,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(drawScale,"drawScale")
		HX_STACK_LINE(112)
		this->m_drawScale = drawScale;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setDrawScale,(void))

Float B2DebugDraw_obj::getDrawScale( ){
	HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","getDrawScale",0x17ea68a0,"box2D.dynamics.B2DebugDraw.getDrawScale","box2D/dynamics/B2DebugDraw.hx",119,0x7faf8720)
	HX_STACK_THIS(this)
	HX_STACK_LINE(119)
	return this->m_drawScale;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getDrawScale,return )

Void B2DebugDraw_obj::setLineThickness( Float lineThickness){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","setLineThickness",0xbdc2520e,"box2D.dynamics.B2DebugDraw.setLineThickness","box2D/dynamics/B2DebugDraw.hx",126,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(lineThickness,"lineThickness")
		HX_STACK_LINE(126)
		this->m_lineThickness = lineThickness;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setLineThickness,(void))

Float B2DebugDraw_obj::getLineThickness( ){
	HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","getLineThickness",0x6780649a,"box2D.dynamics.B2DebugDraw.getLineThickness","box2D/dynamics/B2DebugDraw.hx",133,0x7faf8720)
	HX_STACK_THIS(this)
	HX_STACK_LINE(133)
	return this->m_lineThickness;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getLineThickness,return )

Void B2DebugDraw_obj::setAlpha( Float alpha){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","setAlpha",0xe291008c,"box2D.dynamics.B2DebugDraw.setAlpha","box2D/dynamics/B2DebugDraw.hx",140,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(140)
		this->m_alpha = alpha;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setAlpha,(void))

Float B2DebugDraw_obj::getAlpha( ){
	HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","getAlpha",0x3433a718,"box2D.dynamics.B2DebugDraw.getAlpha","box2D/dynamics/B2DebugDraw.hx",147,0x7faf8720)
	HX_STACK_THIS(this)
	HX_STACK_LINE(147)
	return this->m_alpha;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getAlpha,return )

Void B2DebugDraw_obj::setFillAlpha( Float alpha){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","setFillAlpha",0xdc475609,"box2D.dynamics.B2DebugDraw.setFillAlpha","box2D/dynamics/B2DebugDraw.hx",154,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(154)
		this->m_fillAlpha = alpha;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setFillAlpha,(void))

Float B2DebugDraw_obj::getFillAlpha( ){
	HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","getFillAlpha",0xc74e3295,"box2D.dynamics.B2DebugDraw.getFillAlpha","box2D/dynamics/B2DebugDraw.hx",161,0x7faf8720)
	HX_STACK_THIS(this)
	HX_STACK_LINE(161)
	return this->m_fillAlpha;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getFillAlpha,return )

Void B2DebugDraw_obj::setXFormScale( Float xformScale){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","setXFormScale",0x5f897720,"box2D.dynamics.B2DebugDraw.setXFormScale","box2D/dynamics/B2DebugDraw.hx",168,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(xformScale,"xformScale")
		HX_STACK_LINE(168)
		this->m_xformScale = xformScale;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setXFormScale,(void))

Float B2DebugDraw_obj::getXFormScale( ){
	HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","getXFormScale",0x1a839514,"box2D.dynamics.B2DebugDraw.getXFormScale","box2D/dynamics/B2DebugDraw.hx",175,0x7faf8720)
	HX_STACK_THIS(this)
	HX_STACK_LINE(175)
	return this->m_xformScale;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getXFormScale,return )

Void B2DebugDraw_obj::drawPolygon( Array< ::Dynamic > vertices,int vertexCount,::box2D::common::B2Color color){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","drawPolygon",0xb52394a6,"box2D.dynamics.B2DebugDraw.drawPolygon","box2D/dynamics/B2DebugDraw.hx",181,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(vertices,"vertices")
		HX_STACK_ARG(vertexCount,"vertexCount")
		HX_STACK_ARG(color,"color")
		HX_STACK_LINE(183)
		int _g = color->get_color();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(183)
		this->m_sprite->get_graphics()->lineStyle(this->m_lineThickness,_g,this->m_alpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(184)
		this->m_sprite->get_graphics()->moveTo((vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x * this->m_drawScale),(vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y * this->m_drawScale));
		HX_STACK_LINE(185)
		{
			HX_STACK_LINE(185)
			int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(185)
			while((true)){
				HX_STACK_LINE(185)
				if ((!(((_g1 < vertexCount))))){
					HX_STACK_LINE(185)
					break;
				}
				HX_STACK_LINE(185)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(186)
				this->m_sprite->get_graphics()->lineTo((vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->x * this->m_drawScale),(vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->y * this->m_drawScale));
			}
		}
		HX_STACK_LINE(188)
		this->m_sprite->get_graphics()->lineTo((vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x * this->m_drawScale),(vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DebugDraw_obj,drawPolygon,(void))

Void B2DebugDraw_obj::drawSolidPolygon( Array< ::Dynamic > vertices,int vertexCount,::box2D::common::B2Color color){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","drawSolidPolygon",0xc4042fe3,"box2D.dynamics.B2DebugDraw.drawSolidPolygon","box2D/dynamics/B2DebugDraw.hx",195,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(vertices,"vertices")
		HX_STACK_ARG(vertexCount,"vertexCount")
		HX_STACK_ARG(color,"color")
		HX_STACK_LINE(197)
		int _g = color->get_color();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(197)
		this->m_sprite->get_graphics()->lineStyle(this->m_lineThickness,_g,this->m_alpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(198)
		this->m_sprite->get_graphics()->moveTo((vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x * this->m_drawScale),(vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y * this->m_drawScale));
		HX_STACK_LINE(199)
		int _g1 = color->get_color();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(199)
		this->m_sprite->get_graphics()->beginFill(_g1,this->m_fillAlpha);
		HX_STACK_LINE(200)
		{
			HX_STACK_LINE(200)
			int _g2 = (int)1;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(200)
			while((true)){
				HX_STACK_LINE(200)
				if ((!(((_g2 < vertexCount))))){
					HX_STACK_LINE(200)
					break;
				}
				HX_STACK_LINE(200)
				int i = (_g2)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(201)
				this->m_sprite->get_graphics()->lineTo((vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->x * this->m_drawScale),(vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->y * this->m_drawScale));
			}
		}
		HX_STACK_LINE(203)
		this->m_sprite->get_graphics()->lineTo((vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x * this->m_drawScale),(vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y * this->m_drawScale));
		HX_STACK_LINE(204)
		this->m_sprite->get_graphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DebugDraw_obj,drawSolidPolygon,(void))

Void B2DebugDraw_obj::drawCircle( ::box2D::common::math::B2Vec2 center,Float radius,::box2D::common::B2Color color){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","drawCircle",0xfc174964,"box2D.dynamics.B2DebugDraw.drawCircle","box2D/dynamics/B2DebugDraw.hx",211,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(center,"center")
		HX_STACK_ARG(radius,"radius")
		HX_STACK_ARG(color,"color")
		HX_STACK_LINE(213)
		int _g = color->get_color();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(213)
		this->m_sprite->get_graphics()->lineStyle(this->m_lineThickness,_g,this->m_alpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(214)
		this->m_sprite->get_graphics()->drawCircle((center->x * this->m_drawScale),(center->y * this->m_drawScale),(radius * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DebugDraw_obj,drawCircle,(void))

Void B2DebugDraw_obj::drawSolidCircle( ::box2D::common::math::B2Vec2 center,Float radius,::box2D::common::math::B2Vec2 axis,::box2D::common::B2Color color){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","drawSolidCircle",0xaaa6a4c7,"box2D.dynamics.B2DebugDraw.drawSolidCircle","box2D/dynamics/B2DebugDraw.hx",221,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(center,"center")
		HX_STACK_ARG(radius,"radius")
		HX_STACK_ARG(axis,"axis")
		HX_STACK_ARG(color,"color")
		HX_STACK_LINE(223)
		int _g = color->get_color();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(223)
		this->m_sprite->get_graphics()->lineStyle(this->m_lineThickness,_g,this->m_alpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(224)
		this->m_sprite->get_graphics()->moveTo((int)0,(int)0);
		HX_STACK_LINE(225)
		int _g1 = color->get_color();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(225)
		this->m_sprite->get_graphics()->beginFill(_g1,this->m_fillAlpha);
		HX_STACK_LINE(226)
		this->m_sprite->get_graphics()->drawCircle((center->x * this->m_drawScale),(center->y * this->m_drawScale),(radius * this->m_drawScale));
		HX_STACK_LINE(227)
		this->m_sprite->get_graphics()->endFill();
		HX_STACK_LINE(228)
		this->m_sprite->get_graphics()->moveTo((center->x * this->m_drawScale),(center->y * this->m_drawScale));
		HX_STACK_LINE(229)
		this->m_sprite->get_graphics()->lineTo((((center->x + (axis->x * radius))) * this->m_drawScale),(((center->y + (axis->y * radius))) * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2DebugDraw_obj,drawSolidCircle,(void))

Void B2DebugDraw_obj::drawSegment( ::box2D::common::math::B2Vec2 p1,::box2D::common::math::B2Vec2 p2,::box2D::common::B2Color color){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","drawSegment",0x496161df,"box2D.dynamics.B2DebugDraw.drawSegment","box2D/dynamics/B2DebugDraw.hx",237,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p1,"p1")
		HX_STACK_ARG(p2,"p2")
		HX_STACK_ARG(color,"color")
		HX_STACK_LINE(239)
		int _g = color->get_color();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(239)
		this->m_sprite->get_graphics()->lineStyle(this->m_lineThickness,_g,this->m_alpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(240)
		this->m_sprite->get_graphics()->moveTo((p1->x * this->m_drawScale),(p1->y * this->m_drawScale));
		HX_STACK_LINE(241)
		this->m_sprite->get_graphics()->lineTo((p2->x * this->m_drawScale),(p2->y * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DebugDraw_obj,drawSegment,(void))

Void B2DebugDraw_obj::drawTransform( ::box2D::common::math::B2Transform xf){
{
		HX_STACK_FRAME("box2D.dynamics.B2DebugDraw","drawTransform",0x9f8fa298,"box2D.dynamics.B2DebugDraw.drawTransform","box2D/dynamics/B2DebugDraw.hx",249,0x7faf8720)
		HX_STACK_THIS(this)
		HX_STACK_ARG(xf,"xf")
		HX_STACK_LINE(251)
		this->m_sprite->get_graphics()->lineStyle(this->m_lineThickness,(int)16711680,this->m_alpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(252)
		this->m_sprite->get_graphics()->moveTo((xf->position->x * this->m_drawScale),(xf->position->y * this->m_drawScale));
		HX_STACK_LINE(253)
		this->m_sprite->get_graphics()->lineTo((((xf->position->x + (this->m_xformScale * xf->R->col1->x))) * this->m_drawScale),(((xf->position->y + (this->m_xformScale * xf->R->col1->y))) * this->m_drawScale));
		HX_STACK_LINE(255)
		this->m_sprite->get_graphics()->lineStyle(this->m_lineThickness,(int)65280,this->m_alpha,null(),null(),null(),null(),null());
		HX_STACK_LINE(256)
		this->m_sprite->get_graphics()->moveTo((xf->position->x * this->m_drawScale),(xf->position->y * this->m_drawScale));
		HX_STACK_LINE(257)
		this->m_sprite->get_graphics()->lineTo((((xf->position->x + (this->m_xformScale * xf->R->col2->x))) * this->m_drawScale),(((xf->position->y + (this->m_xformScale * xf->R->col2->y))) * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,drawTransform,(void))

int B2DebugDraw_obj::e_shapeBit;

int B2DebugDraw_obj::e_jointBit;

int B2DebugDraw_obj::e_aabbBit;

int B2DebugDraw_obj::e_pairBit;

int B2DebugDraw_obj::e_centerOfMassBit;

int B2DebugDraw_obj::e_controllerBit;


B2DebugDraw_obj::B2DebugDraw_obj()
{
}

void B2DebugDraw_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DebugDraw);
	HX_MARK_MEMBER_NAME(m_drawFlags,"m_drawFlags");
	HX_MARK_MEMBER_NAME(m_sprite,"m_sprite");
	HX_MARK_MEMBER_NAME(m_drawScale,"m_drawScale");
	HX_MARK_MEMBER_NAME(m_lineThickness,"m_lineThickness");
	HX_MARK_MEMBER_NAME(m_alpha,"m_alpha");
	HX_MARK_MEMBER_NAME(m_fillAlpha,"m_fillAlpha");
	HX_MARK_MEMBER_NAME(m_xformScale,"m_xformScale");
	HX_MARK_END_CLASS();
}

void B2DebugDraw_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_drawFlags,"m_drawFlags");
	HX_VISIT_MEMBER_NAME(m_sprite,"m_sprite");
	HX_VISIT_MEMBER_NAME(m_drawScale,"m_drawScale");
	HX_VISIT_MEMBER_NAME(m_lineThickness,"m_lineThickness");
	HX_VISIT_MEMBER_NAME(m_alpha,"m_alpha");
	HX_VISIT_MEMBER_NAME(m_fillAlpha,"m_fillAlpha");
	HX_VISIT_MEMBER_NAME(m_xformScale,"m_xformScale");
}

Dynamic B2DebugDraw_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_alpha") ) { return m_alpha; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setFlags") ) { return setFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"getFlags") ) { return getFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"setAlpha") ) { return setAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"getAlpha") ) { return getAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"m_sprite") ) { return m_sprite; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_aabbBit") ) { return e_aabbBit; }
		if (HX_FIELD_EQ(inName,"e_pairBit") ) { return e_pairBit; }
		if (HX_FIELD_EQ(inName,"setSprite") ) { return setSprite_dyn(); }
		if (HX_FIELD_EQ(inName,"getSprite") ) { return getSprite_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"e_shapeBit") ) { return e_shapeBit; }
		if (HX_FIELD_EQ(inName,"e_jointBit") ) { return e_jointBit; }
		if (HX_FIELD_EQ(inName,"clearFlags") ) { return clearFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"drawCircle") ) { return drawCircle_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"appendFlags") ) { return appendFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"drawPolygon") ) { return drawPolygon_dyn(); }
		if (HX_FIELD_EQ(inName,"drawSegment") ) { return drawSegment_dyn(); }
		if (HX_FIELD_EQ(inName,"m_drawFlags") ) { return m_drawFlags; }
		if (HX_FIELD_EQ(inName,"m_drawScale") ) { return m_drawScale; }
		if (HX_FIELD_EQ(inName,"m_fillAlpha") ) { return m_fillAlpha; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setDrawScale") ) { return setDrawScale_dyn(); }
		if (HX_FIELD_EQ(inName,"getDrawScale") ) { return getDrawScale_dyn(); }
		if (HX_FIELD_EQ(inName,"setFillAlpha") ) { return setFillAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"getFillAlpha") ) { return getFillAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"m_xformScale") ) { return m_xformScale; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setXFormScale") ) { return setXFormScale_dyn(); }
		if (HX_FIELD_EQ(inName,"getXFormScale") ) { return getXFormScale_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTransform") ) { return drawTransform_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"e_controllerBit") ) { return e_controllerBit; }
		if (HX_FIELD_EQ(inName,"drawSolidCircle") ) { return drawSolidCircle_dyn(); }
		if (HX_FIELD_EQ(inName,"m_lineThickness") ) { return m_lineThickness; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setLineThickness") ) { return setLineThickness_dyn(); }
		if (HX_FIELD_EQ(inName,"getLineThickness") ) { return getLineThickness_dyn(); }
		if (HX_FIELD_EQ(inName,"drawSolidPolygon") ) { return drawSolidPolygon_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"e_centerOfMassBit") ) { return e_centerOfMassBit; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2DebugDraw_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_alpha") ) { m_alpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_sprite") ) { m_sprite=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_aabbBit") ) { e_aabbBit=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_pairBit") ) { e_pairBit=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"e_shapeBit") ) { e_shapeBit=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_jointBit") ) { e_jointBit=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_drawFlags") ) { m_drawFlags=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_drawScale") ) { m_drawScale=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fillAlpha") ) { m_fillAlpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_xformScale") ) { m_xformScale=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"e_controllerBit") ) { e_controllerBit=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_lineThickness") ) { m_lineThickness=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"e_centerOfMassBit") ) { e_centerOfMassBit=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2DebugDraw_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_drawFlags"));
	outFields->push(HX_CSTRING("m_sprite"));
	outFields->push(HX_CSTRING("m_drawScale"));
	outFields->push(HX_CSTRING("m_lineThickness"));
	outFields->push(HX_CSTRING("m_alpha"));
	outFields->push(HX_CSTRING("m_fillAlpha"));
	outFields->push(HX_CSTRING("m_xformScale"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("e_shapeBit"),
	HX_CSTRING("e_jointBit"),
	HX_CSTRING("e_aabbBit"),
	HX_CSTRING("e_pairBit"),
	HX_CSTRING("e_centerOfMassBit"),
	HX_CSTRING("e_controllerBit"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(B2DebugDraw_obj,m_drawFlags),HX_CSTRING("m_drawFlags")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(B2DebugDraw_obj,m_sprite),HX_CSTRING("m_sprite")},
	{hx::fsFloat,(int)offsetof(B2DebugDraw_obj,m_drawScale),HX_CSTRING("m_drawScale")},
	{hx::fsFloat,(int)offsetof(B2DebugDraw_obj,m_lineThickness),HX_CSTRING("m_lineThickness")},
	{hx::fsFloat,(int)offsetof(B2DebugDraw_obj,m_alpha),HX_CSTRING("m_alpha")},
	{hx::fsFloat,(int)offsetof(B2DebugDraw_obj,m_fillAlpha),HX_CSTRING("m_fillAlpha")},
	{hx::fsFloat,(int)offsetof(B2DebugDraw_obj,m_xformScale),HX_CSTRING("m_xformScale")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("setFlags"),
	HX_CSTRING("getFlags"),
	HX_CSTRING("appendFlags"),
	HX_CSTRING("clearFlags"),
	HX_CSTRING("setSprite"),
	HX_CSTRING("getSprite"),
	HX_CSTRING("setDrawScale"),
	HX_CSTRING("getDrawScale"),
	HX_CSTRING("setLineThickness"),
	HX_CSTRING("getLineThickness"),
	HX_CSTRING("setAlpha"),
	HX_CSTRING("getAlpha"),
	HX_CSTRING("setFillAlpha"),
	HX_CSTRING("getFillAlpha"),
	HX_CSTRING("setXFormScale"),
	HX_CSTRING("getXFormScale"),
	HX_CSTRING("drawPolygon"),
	HX_CSTRING("drawSolidPolygon"),
	HX_CSTRING("drawCircle"),
	HX_CSTRING("drawSolidCircle"),
	HX_CSTRING("drawSegment"),
	HX_CSTRING("drawTransform"),
	HX_CSTRING("m_drawFlags"),
	HX_CSTRING("m_sprite"),
	HX_CSTRING("m_drawScale"),
	HX_CSTRING("m_lineThickness"),
	HX_CSTRING("m_alpha"),
	HX_CSTRING("m_fillAlpha"),
	HX_CSTRING("m_xformScale"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_shapeBit,"e_shapeBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_jointBit,"e_jointBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_aabbBit,"e_aabbBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_pairBit,"e_pairBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_centerOfMassBit,"e_centerOfMassBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_controllerBit,"e_controllerBit");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2DebugDraw_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2DebugDraw_obj::e_shapeBit,"e_shapeBit");
	HX_VISIT_MEMBER_NAME(B2DebugDraw_obj::e_jointBit,"e_jointBit");
	HX_VISIT_MEMBER_NAME(B2DebugDraw_obj::e_aabbBit,"e_aabbBit");
	HX_VISIT_MEMBER_NAME(B2DebugDraw_obj::e_pairBit,"e_pairBit");
	HX_VISIT_MEMBER_NAME(B2DebugDraw_obj::e_centerOfMassBit,"e_centerOfMassBit");
	HX_VISIT_MEMBER_NAME(B2DebugDraw_obj::e_controllerBit,"e_controllerBit");
};

#endif

Class B2DebugDraw_obj::__mClass;

void B2DebugDraw_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2DebugDraw"), hx::TCanCast< B2DebugDraw_obj> ,sStaticFields,sMemberFields,
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

void B2DebugDraw_obj::__boot()
{
	e_shapeBit= (int)1;
	e_jointBit= (int)2;
	e_aabbBit= (int)4;
	e_pairBit= (int)8;
	e_centerOfMassBit= (int)16;
	e_controllerBit= (int)32;
}

} // end namespace box2D
} // end namespace dynamics
