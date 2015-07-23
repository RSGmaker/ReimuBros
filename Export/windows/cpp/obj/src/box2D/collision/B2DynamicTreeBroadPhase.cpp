#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTree
#include <box2D/collision/B2DynamicTree.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreeBroadPhase
#include <box2D/collision/B2DynamicTreeBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreeNode
#include <box2D/collision/B2DynamicTreeNode.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreePair
#include <box2D/collision/B2DynamicTreePair.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_IBroadPhase
#include <box2D/collision/IBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2DynamicTreeBroadPhase_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","new",0x75e5760b,"box2D.collision.B2DynamicTreeBroadPhase.new","box2D/collision/B2DynamicTreeBroadPhase.hx",215,0xa5294987)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(217)
	::box2D::collision::B2DynamicTree _g = ::box2D::collision::B2DynamicTree_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(217)
	this->m_tree = _g;
	HX_STACK_LINE(218)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(218)
	this->m_moveBuffer = _g1;
	HX_STACK_LINE(220)
	Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(220)
	this->m_pairBuffer = _g2;
	HX_STACK_LINE(221)
	this->m_pairCount = (int)0;
	HX_STACK_LINE(223)
	this->m_proxyCount = (int)0;
}
;
	return null();
}

//B2DynamicTreeBroadPhase_obj::~B2DynamicTreeBroadPhase_obj() { }

Dynamic B2DynamicTreeBroadPhase_obj::__CreateEmpty() { return  new B2DynamicTreeBroadPhase_obj; }
hx::ObjectPtr< B2DynamicTreeBroadPhase_obj > B2DynamicTreeBroadPhase_obj::__new()
{  hx::ObjectPtr< B2DynamicTreeBroadPhase_obj > result = new B2DynamicTreeBroadPhase_obj();
	result->__construct();
	return result;}

Dynamic B2DynamicTreeBroadPhase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DynamicTreeBroadPhase_obj > result = new B2DynamicTreeBroadPhase_obj();
	result->__construct();
	return result;}

hx::Object *B2DynamicTreeBroadPhase_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::box2D::collision::IBroadPhase_obj)) return operator ::box2D::collision::IBroadPhase_obj *();
	return super::__ToInterface(inType);
}

Dynamic B2DynamicTreeBroadPhase_obj::createProxy( ::box2D::collision::B2AABB aabb,Dynamic userData){
	HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","createProxy",0x608aee7d,"box2D.collision.B2DynamicTreeBroadPhase.createProxy","box2D/collision/B2DynamicTreeBroadPhase.hx",19,0xa5294987)
	HX_STACK_THIS(this)
	HX_STACK_ARG(aabb,"aabb")
	HX_STACK_ARG(userData,"userData")
	HX_STACK_LINE(20)
	::box2D::collision::B2DynamicTreeNode proxy = this->m_tree->createProxy(aabb,userData);		HX_STACK_VAR(proxy,"proxy");
	HX_STACK_LINE(21)
	++(this->m_proxyCount);
	HX_STACK_LINE(22)
	this->bufferMove(proxy);
	HX_STACK_LINE(23)
	return proxy;
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,createProxy,return )

Void B2DynamicTreeBroadPhase_obj::destroyProxy( Dynamic proxy){
{
		HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","destroyProxy",0xfbdfb409,"box2D.collision.B2DynamicTreeBroadPhase.destroyProxy","box2D/collision/B2DynamicTreeBroadPhase.hx",30,0xa5294987)
		HX_STACK_THIS(this)
		HX_STACK_ARG(proxy,"proxy")
		HX_STACK_LINE(31)
		this->unBufferMove(proxy);
		HX_STACK_LINE(32)
		--(this->m_proxyCount);
		HX_STACK_LINE(33)
		this->m_tree->destroyProxy(proxy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,destroyProxy,(void))

Void B2DynamicTreeBroadPhase_obj::moveProxy( Dynamic proxy,::box2D::collision::B2AABB aabb,::box2D::common::math::B2Vec2 displacement){
{
		HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","moveProxy",0x1b087588,"box2D.collision.B2DynamicTreeBroadPhase.moveProxy","box2D/collision/B2DynamicTreeBroadPhase.hx",41,0xa5294987)
		HX_STACK_THIS(this)
		HX_STACK_ARG(proxy,"proxy")
		HX_STACK_ARG(aabb,"aabb")
		HX_STACK_ARG(displacement,"displacement")
		HX_STACK_LINE(42)
		bool buffer = this->m_tree->moveProxy(proxy,aabb,displacement);		HX_STACK_VAR(buffer,"buffer");
		HX_STACK_LINE(43)
		if ((buffer)){
			HX_STACK_LINE(45)
			this->bufferMove(proxy);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DynamicTreeBroadPhase_obj,moveProxy,(void))

bool B2DynamicTreeBroadPhase_obj::testOverlap( Dynamic proxyA,Dynamic proxyB){
	HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","testOverlap",0xd458fa00,"box2D.collision.B2DynamicTreeBroadPhase.testOverlap","box2D/collision/B2DynamicTreeBroadPhase.hx",50,0xa5294987)
	HX_STACK_THIS(this)
	HX_STACK_ARG(proxyA,"proxyA")
	HX_STACK_ARG(proxyB,"proxyB")
	HX_STACK_LINE(51)
	::box2D::collision::B2AABB aabbA = this->m_tree->getFatAABB(proxyA);		HX_STACK_VAR(aabbA,"aabbA");
	HX_STACK_LINE(52)
	::box2D::collision::B2AABB aabbB = this->m_tree->getFatAABB(proxyB);		HX_STACK_VAR(aabbB,"aabbB");
	HX_STACK_LINE(53)
	return aabbA->testOverlap(aabbB);
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,testOverlap,return )

Dynamic B2DynamicTreeBroadPhase_obj::getUserData( Dynamic proxy){
	HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","getUserData",0x999c2176,"box2D.collision.B2DynamicTreeBroadPhase.getUserData","box2D/collision/B2DynamicTreeBroadPhase.hx",61,0xa5294987)
	HX_STACK_THIS(this)
	HX_STACK_ARG(proxy,"proxy")
	HX_STACK_LINE(61)
	return this->m_tree->getUserData(proxy);
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,getUserData,return )

::box2D::collision::B2AABB B2DynamicTreeBroadPhase_obj::getFatAABB( Dynamic proxy){
	HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","getFatAABB",0x25ffc1b8,"box2D.collision.B2DynamicTreeBroadPhase.getFatAABB","box2D/collision/B2DynamicTreeBroadPhase.hx",69,0xa5294987)
	HX_STACK_THIS(this)
	HX_STACK_ARG(proxy,"proxy")
	HX_STACK_LINE(69)
	return this->m_tree->getFatAABB(proxy);
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,getFatAABB,return )

int B2DynamicTreeBroadPhase_obj::getProxyCount( ){
	HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","getProxyCount",0xdab99d22,"box2D.collision.B2DynamicTreeBroadPhase.getProxyCount","box2D/collision/B2DynamicTreeBroadPhase.hx",77,0xa5294987)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	return this->m_proxyCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DynamicTreeBroadPhase_obj,getProxyCount,return )

Void B2DynamicTreeBroadPhase_obj::updatePairs( Dynamic callbackMethod){
{
		HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","updatePairs",0x1166ecfb,"box2D.collision.B2DynamicTreeBroadPhase.updatePairs","box2D/collision/B2DynamicTreeBroadPhase.hx",84,0xa5294987)
		HX_STACK_THIS(this)
		HX_STACK_ARG(callbackMethod,"callbackMethod")
		HX_STACK_LINE(83)
		Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(85)
		this->m_pairCount = (int)0;
		HX_STACK_LINE(87)
		{
			HX_STACK_LINE(87)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(87)
			Array< ::Dynamic > _g1 = this->m_moveBuffer;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(87)
			while((true)){
				HX_STACK_LINE(87)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(87)
					break;
				}
				HX_STACK_LINE(87)
				Array< ::Dynamic > queryProxy = Array_obj< ::Dynamic >::__new().Add(_g1->__get(_g).StaticCast< ::box2D::collision::B2DynamicTreeNode >());		HX_STACK_VAR(queryProxy,"queryProxy");
				HX_STACK_LINE(87)
				++(_g);

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,Array< ::Dynamic >,queryProxy,Array< ::Dynamic >,_g2)
				bool run(::box2D::collision::B2DynamicTreeNode proxy){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","box2D/collision/B2DynamicTreeBroadPhase.hx",90,0xa5294987)
					HX_STACK_ARG(proxy,"proxy")
					{
						HX_STACK_LINE(92)
						if (((proxy == queryProxy->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeNode >()))){
							HX_STACK_LINE(93)
							return true;
						}
						HX_STACK_LINE(96)
						if (((_g2->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeBroadPhase >()->m_pairCount == _g2->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeBroadPhase >()->m_pairBuffer->length))){
							HX_STACK_LINE(98)
							_g2->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeBroadPhase >()->m_pairBuffer[_g2->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeBroadPhase >()->m_pairCount] = ::box2D::collision::B2DynamicTreePair_obj::__new();
						}
						HX_STACK_LINE(101)
						::box2D::collision::B2DynamicTreePair pair = _g2->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeBroadPhase >()->m_pairBuffer->__get(_g2->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeBroadPhase >()->m_pairCount).StaticCast< ::box2D::collision::B2DynamicTreePair >();		HX_STACK_VAR(pair,"pair");
						HX_STACK_LINE(103)
						if (((proxy->id < queryProxy->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeNode >()->id))){
							HX_STACK_LINE(105)
							pair->proxyA = proxy;
							HX_STACK_LINE(106)
							pair->proxyB = queryProxy->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeNode >();
						}
						else{
							HX_STACK_LINE(110)
							pair->proxyA = queryProxy->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeNode >();
							HX_STACK_LINE(111)
							pair->proxyB = proxy;
						}
						HX_STACK_LINE(116)
						++(_g2->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeBroadPhase >()->m_pairCount);
						HX_STACK_LINE(118)
						return true;
					}
					return null();
				}
				HX_END_LOCAL_FUNC1(return)

				HX_STACK_LINE(89)
				Dynamic queryCallback =  Dynamic(new _Function_3_1(queryProxy,_g2));		HX_STACK_VAR(queryCallback,"queryCallback");
				HX_STACK_LINE(122)
				::box2D::collision::B2AABB fatAABB = this->m_tree->getFatAABB(queryProxy->__get((int)0).StaticCast< ::box2D::collision::B2DynamicTreeNode >());		HX_STACK_VAR(fatAABB,"fatAABB");
				HX_STACK_LINE(123)
				this->m_tree->query(queryCallback,fatAABB);
			}
		}
		HX_STACK_LINE(127)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(127)
		this->m_moveBuffer = _g;
		HX_STACK_LINE(136)
		bool pairing = true;		HX_STACK_VAR(pairing,"pairing");
		HX_STACK_LINE(137)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(138)
		while((true)){
			HX_STACK_LINE(138)
			if ((!(pairing))){
				HX_STACK_LINE(138)
				break;
			}
			HX_STACK_LINE(140)
			if (((i >= this->m_pairCount))){
				HX_STACK_LINE(142)
				pairing = false;
			}
			else{
				HX_STACK_LINE(146)
				::box2D::collision::B2DynamicTreePair primaryPair = this->m_pairBuffer->__get(i).StaticCast< ::box2D::collision::B2DynamicTreePair >();		HX_STACK_VAR(primaryPair,"primaryPair");
				HX_STACK_LINE(147)
				Dynamic userDataA = this->m_tree->getUserData(primaryPair->proxyA);		HX_STACK_VAR(userDataA,"userDataA");
				HX_STACK_LINE(148)
				Dynamic userDataB = this->m_tree->getUserData(primaryPair->proxyB);		HX_STACK_VAR(userDataB,"userDataB");
				HX_STACK_LINE(149)
				callbackMethod(userDataA,userDataB);
				HX_STACK_LINE(150)
				++(i);
				HX_STACK_LINE(153)
				while((true)){
					HX_STACK_LINE(153)
					if ((!(((i < this->m_pairCount))))){
						HX_STACK_LINE(153)
						break;
					}
					HX_STACK_LINE(155)
					::box2D::collision::B2DynamicTreePair pair = this->m_pairBuffer->__get(i).StaticCast< ::box2D::collision::B2DynamicTreePair >();		HX_STACK_VAR(pair,"pair");
					HX_STACK_LINE(156)
					if (((bool((pair->proxyA != primaryPair->proxyA)) || bool((pair->proxyB != primaryPair->proxyB))))){
						HX_STACK_LINE(158)
						break;
					}
					HX_STACK_LINE(160)
					++(i);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,updatePairs,(void))

Void B2DynamicTreeBroadPhase_obj::query( Dynamic callbackMethod,::box2D::collision::B2AABB aabb){
{
		HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","query",0x97713173,"box2D.collision.B2DynamicTreeBroadPhase.query","box2D/collision/B2DynamicTreeBroadPhase.hx",172,0xa5294987)
		HX_STACK_THIS(this)
		HX_STACK_ARG(callbackMethod,"callbackMethod")
		HX_STACK_ARG(aabb,"aabb")
		HX_STACK_LINE(172)
		this->m_tree->query(callbackMethod,aabb);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,query,(void))

Void B2DynamicTreeBroadPhase_obj::rayCast( Dynamic callbackMethod,::box2D::collision::B2RayCastInput input){
{
		HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","rayCast",0xca89b4f4,"box2D.collision.B2DynamicTreeBroadPhase.rayCast","box2D/collision/B2DynamicTreeBroadPhase.hx",180,0xa5294987)
		HX_STACK_THIS(this)
		HX_STACK_ARG(callbackMethod,"callbackMethod")
		HX_STACK_ARG(input,"input")
		HX_STACK_LINE(180)
		this->m_tree->rayCast(callbackMethod,input);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,rayCast,(void))

Void B2DynamicTreeBroadPhase_obj::validate( ){
{
		HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","validate",0x0342bf0b,"box2D.collision.B2DynamicTreeBroadPhase.validate","box2D/collision/B2DynamicTreeBroadPhase.hx",185,0xa5294987)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2DynamicTreeBroadPhase_obj,validate,(void))

Void B2DynamicTreeBroadPhase_obj::rebalance( int iterations){
{
		HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","rebalance",0x38a71db4,"box2D.collision.B2DynamicTreeBroadPhase.rebalance","box2D/collision/B2DynamicTreeBroadPhase.hx",191,0xa5294987)
		HX_STACK_THIS(this)
		HX_STACK_ARG(iterations,"iterations")
		HX_STACK_LINE(191)
		this->m_tree->rebalance(iterations);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,rebalance,(void))

Void B2DynamicTreeBroadPhase_obj::bufferMove( ::box2D::collision::B2DynamicTreeNode proxy){
{
		HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","bufferMove",0x204081e6,"box2D.collision.B2DynamicTreeBroadPhase.bufferMove","box2D/collision/B2DynamicTreeBroadPhase.hx",199,0xa5294987)
		HX_STACK_THIS(this)
		HX_STACK_ARG(proxy,"proxy")
		HX_STACK_LINE(199)
		this->m_moveBuffer[this->m_moveBuffer->length] = proxy;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,bufferMove,(void))

Void B2DynamicTreeBroadPhase_obj::unBufferMove( ::box2D::collision::B2DynamicTreeNode proxy){
{
		HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","unBufferMove",0x3d814cdf,"box2D.collision.B2DynamicTreeBroadPhase.unBufferMove","box2D/collision/B2DynamicTreeBroadPhase.hx",204,0xa5294987)
		HX_STACK_THIS(this)
		HX_STACK_ARG(proxy,"proxy")
		HX_STACK_LINE(204)
		this->m_moveBuffer->remove(proxy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,unBufferMove,(void))

int B2DynamicTreeBroadPhase_obj::comparePairs( ::box2D::collision::B2DynamicTreePair pair1,::box2D::collision::B2DynamicTreePair pair2){
	HX_STACK_FRAME("box2D.collision.B2DynamicTreeBroadPhase","comparePairs",0x9b4e6929,"box2D.collision.B2DynamicTreeBroadPhase.comparePairs","box2D/collision/B2DynamicTreeBroadPhase.hx",212,0xa5294987)
	HX_STACK_THIS(this)
	HX_STACK_ARG(pair1,"pair1")
	HX_STACK_ARG(pair2,"pair2")
	HX_STACK_LINE(212)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,comparePairs,return )


B2DynamicTreeBroadPhase_obj::B2DynamicTreeBroadPhase_obj()
{
}

void B2DynamicTreeBroadPhase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DynamicTreeBroadPhase);
	HX_MARK_MEMBER_NAME(m_tree,"m_tree");
	HX_MARK_MEMBER_NAME(m_proxyCount,"m_proxyCount");
	HX_MARK_MEMBER_NAME(m_moveBuffer,"m_moveBuffer");
	HX_MARK_MEMBER_NAME(m_pairBuffer,"m_pairBuffer");
	HX_MARK_MEMBER_NAME(m_pairCount,"m_pairCount");
	HX_MARK_END_CLASS();
}

void B2DynamicTreeBroadPhase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_tree,"m_tree");
	HX_VISIT_MEMBER_NAME(m_proxyCount,"m_proxyCount");
	HX_VISIT_MEMBER_NAME(m_moveBuffer,"m_moveBuffer");
	HX_VISIT_MEMBER_NAME(m_pairBuffer,"m_pairBuffer");
	HX_VISIT_MEMBER_NAME(m_pairCount,"m_pairCount");
}

Dynamic B2DynamicTreeBroadPhase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"query") ) { return query_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_tree") ) { return m_tree; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"validate") ) { return validate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"moveProxy") ) { return moveProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"rebalance") ) { return rebalance_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getFatAABB") ) { return getFatAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"bufferMove") ) { return bufferMove_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createProxy") ) { return createProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"testOverlap") ) { return testOverlap_dyn(); }
		if (HX_FIELD_EQ(inName,"getUserData") ) { return getUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"updatePairs") ) { return updatePairs_dyn(); }
		if (HX_FIELD_EQ(inName,"m_pairCount") ) { return m_pairCount; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"destroyProxy") ) { return destroyProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"unBufferMove") ) { return unBufferMove_dyn(); }
		if (HX_FIELD_EQ(inName,"comparePairs") ) { return comparePairs_dyn(); }
		if (HX_FIELD_EQ(inName,"m_proxyCount") ) { return m_proxyCount; }
		if (HX_FIELD_EQ(inName,"m_moveBuffer") ) { return m_moveBuffer; }
		if (HX_FIELD_EQ(inName,"m_pairBuffer") ) { return m_pairBuffer; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getProxyCount") ) { return getProxyCount_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2DynamicTreeBroadPhase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_tree") ) { m_tree=inValue.Cast< ::box2D::collision::B2DynamicTree >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_pairCount") ) { m_pairCount=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_proxyCount") ) { m_proxyCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_moveBuffer") ) { m_moveBuffer=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_pairBuffer") ) { m_pairBuffer=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2DynamicTreeBroadPhase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_tree"));
	outFields->push(HX_CSTRING("m_proxyCount"));
	outFields->push(HX_CSTRING("m_moveBuffer"));
	outFields->push(HX_CSTRING("m_pairBuffer"));
	outFields->push(HX_CSTRING("m_pairCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::collision::B2DynamicTree*/ ,(int)offsetof(B2DynamicTreeBroadPhase_obj,m_tree),HX_CSTRING("m_tree")},
	{hx::fsInt,(int)offsetof(B2DynamicTreeBroadPhase_obj,m_proxyCount),HX_CSTRING("m_proxyCount")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2DynamicTreeBroadPhase_obj,m_moveBuffer),HX_CSTRING("m_moveBuffer")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2DynamicTreeBroadPhase_obj,m_pairBuffer),HX_CSTRING("m_pairBuffer")},
	{hx::fsInt,(int)offsetof(B2DynamicTreeBroadPhase_obj,m_pairCount),HX_CSTRING("m_pairCount")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("createProxy"),
	HX_CSTRING("destroyProxy"),
	HX_CSTRING("moveProxy"),
	HX_CSTRING("testOverlap"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("getFatAABB"),
	HX_CSTRING("getProxyCount"),
	HX_CSTRING("updatePairs"),
	HX_CSTRING("query"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("validate"),
	HX_CSTRING("rebalance"),
	HX_CSTRING("bufferMove"),
	HX_CSTRING("unBufferMove"),
	HX_CSTRING("comparePairs"),
	HX_CSTRING("m_tree"),
	HX_CSTRING("m_proxyCount"),
	HX_CSTRING("m_moveBuffer"),
	HX_CSTRING("m_pairBuffer"),
	HX_CSTRING("m_pairCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2DynamicTreeBroadPhase_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2DynamicTreeBroadPhase_obj::__mClass,"__mClass");
};

#endif

Class B2DynamicTreeBroadPhase_obj::__mClass;

void B2DynamicTreeBroadPhase_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DynamicTreeBroadPhase"), hx::TCanCast< B2DynamicTreeBroadPhase_obj> ,sStaticFields,sMemberFields,
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

void B2DynamicTreeBroadPhase_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
