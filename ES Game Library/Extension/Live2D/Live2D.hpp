/*
================================================================================
					 IuWFNgwόQ[vO~O
	     Copyright (c) 2011 Human Academy Sendai. All rights reserved.
================================================================================

 yΞΫnrz
     Microsoft Windows 7Θ~

 yRpCz
     Microsoft VisualC++ 2013

 yvOz
	 Live2D.hpp
				Live2DNXwb_[t@C

 yo[Wz
	 * Version    2015.10.00      2015/08/28  03:10:03

================================================================================
*/

/*
//------------------------------------------------------------------------------
//	p[^[IDκ
//------------------------------------------------------------------------------
"PARAM_ANGLE_X"			// px X
"PARAM_ANGLE_Y"			// px Y
"PARAM_ANGLE_Z"			// px Z
"PARAM_EYE_L_OPEN"		// Άα JΒ
"PARAM_EYE_L_SMILE"		// Άα Ξη
"PARAM_EYE_R_OPEN"		// Eα JΒ
"PARAM_EYE_R_SMILE"		// Eα Ξη
"PARAM_EYE_FORM"		// α Ο`
"PARAM_EYE_BALL_X"		// ΪΚ X
"PARAM_EYE_BALL_Y"		// ΪΚ Y
"PARAM_EYE_BALL_FORM"	// ΪΚ ϋk
"PARAM_BROW_L_Y"		// Άϋ γΊ
"PARAM_BROW_R_Y"		// Eϋ γΊ
"PARAM_BROW_L_X"		// Άϋ ΆE
"PARAM_BROW_R_X"		// Eϋ ΆE
"PARAM_BROW_L_ANGLE"	// Άϋ px
"PARAM_BROW_R_ANGLE"	// Eϋ px
"PARAM_BROW_L_FORM"		// Άϋ Ο`
"PARAM_BROW_R_FORM"		// Eϋ Ο`
"PARAM_MOUTH_FORM"		// ϋ Ο`
"PARAM_MOUTH_OPEN_Y"	// ϋ JΒ
"PARAM_CHEEK"			// Ζκ
"PARAM_BODY_ANGLE_X"	// ΜΜρ] X
"PARAM_BODY_ANGLE_Y"	// ΜΜρ] X
"PARAM_BODY_ANGLE_Z"	// ΜΜρ] Z
"PARAM_BREATH"			// Δz
"PARAM_ARM_L_A"			// Άr A
"PARAM_ARM_R_A"			// Er A
"PARAM_ARM_L_A"			// Άr B
"PARAM_ARM_R_A"			// Er B 
"PARAM_BUST_Y"			// Ή hκ   
"PARAM_HAIR_FRONT"		// ―hκ O
"PARAM_HAIR_BACK"		// ―hκ γ
*/

#ifndef _INC_LIVE2D
#define _INC_LIVE2D

#if defined (_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

//------------------------------------------------------------------------------
//	ιΎ
//------------------------------------------------------------------------------
#define L2D_TARGET_D3D

//------------------------------------------------------------------------------
//	CN[ht@C
//------------------------------------------------------------------------------
#include <Live2D.h>
#include <Live2DModelD3D.h>
#include <..\..\DirectX\Include\d3dx9.h>

#include <list>
#include <set>
#include <vector>

//------------------------------------------------------------------------------
//	LIVE2DFILE\’Μθ`
//------------------------------------------------------------------------------
struct Live2DFile {
	char*                                    ModelFileName;
	std::vector< std::basic_string<char> >   TextureFileName;
};

//------------------------------------------------------------------------------
//	LIVE2DMODEL\’Μθ`
//------------------------------------------------------------------------------
struct Live2DModel {
friend class CLive2D;

private:
	live2d::Live2DModelD3D*           pModel;
	std::vector<IDirect3DTexture9*>   pTexture;

	template <class T>
	inline void SafeRelease(T& x)
	{
		if(x != NULL) {
			x->Release();
			x = NULL;
		}
	}

public:
	D3DXVECTOR3   position;
	D3DXVECTOR3   scale;
	float         rotationZ;

	float         width;
	float         height;

	Live2DModel()
	{
		pModel     = NULL;

		position.x = 0.0f;
		position.y = 0.0f;
		position.z = 0.0f;

		scale   .x = 1.0f;
		scale   .y = 1.0f;
		scale   .z = 1.0f;

		rotationZ  = 0.0f;
	}

	virtual ~Live2DModel()
	{
		const UINT   ARRAY_SIZE = pTexture.size();
		for(UINT i = 0; i < ARRAY_SIZE; i++) {
			if(pTexture[i] != NULL)
				pTexture[i]->Release();
		}

		delete pModel;
	}

	inline void SetScale(const float inScale)
	{
		scale.x = inScale;
		scale.y = inScale;
		scale.z = 1.0f;
	}

//	Live2DModel& operator=(live2d::Live2DModelD3D* pModel)
//	{
//		this->pModel = pModel;
//
//		width  = pModel->getModelImpl()->getCanvasWidth ();
//		height = pModel->getModelImpl()->getCanvasHeight();
//
//		return *this;
//	}

	inline operator live2d::Live2DModelD3D*  () const { return pModel; }
//	inline Live2DModel&            operator* ()       { return *this;  }
	inline live2d::Live2DModelD3D* operator->()       { return pModel; }
};

//------------------------------------------------------------------------------
//	Live2DNXθ`
//------------------------------------------------------------------------------
class CLive2D {
public:
	virtual ~CLive2D();

	// VOgCX^XΜζΎ
	static CLive2D& GetInstance()
	{
		static CLive2D   theLive2D;
		return theLive2D;
	}

	// ϊ»Eπϊ
	bool Initialize(IDirect3DDevice9* pDevice);
	inline bool Attach(IDirect3DDevice9* pDevice) { return Initialize(pDevice); }

	void Release();

	// fΆ¬Eπϊ
	Live2DModel* CreateModelFromFile(const Live2DFile& inFile);

	void ReleaseModel(Live2DModel*& inLive2DModel);
	void ReleaseAllModels();

	// `ζ
	void Begin();
	void End();

	void Draw(Live2DModel& inLive2DModel);
	inline void Draw(Live2DModel* pLive2DModel) { Draw(*pLive2DModel); }

	// veNgέθ
	void SetResourceProtect(void* pResource, const bool inProtect);

private:
	CLive2D();

	template <class T>
	inline void SafeRelease(T& x)
	{
		if(x != NULL) {
			x->Release();
			x = NULL;
		}
	}

	CLive2D(const CLive2D&) = delete;
	CLive2D& operator=(const CLive2D&) = delete;

private:
	IDirect3DDevice9*         m_pDevice;
	std::list<Live2DModel*>   m_ModelList;

	D3DXMATRIXA16             m_View;
	D3DXMATRIXA16             m_Projection;

	std::set<void*>           m_ProtectedResource;
};

//------------------------------------------------------------------------------
//	}Nθ`
//------------------------------------------------------------------------------
inline CLive2D& LIVE2D() { return CLive2D::GetInstance(); }

#endif /* _INC_LIVE2D */