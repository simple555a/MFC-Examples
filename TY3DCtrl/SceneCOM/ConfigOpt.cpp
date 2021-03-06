// ConfigOpt.cpp : CConfigOpt 的实现

#include "stdafx.h"
#include "ConfigOpt.h"
#include <atlstr.h>
#include <istream>
// CConfigOpt

STDMETHODIMP CConfigOpt::FromStringArray(LONG type, VARIANT keys, VARIANT values)
{
    if(keys.vt != (VT_ARRAY|VT_BSTR) || values.vt != (VT_ARRAY|VT_BSTR))
		return E_FAIL;
	LPSAFEARRAY parrKey = keys.parray;
	LPSAFEARRAY parrValues = values.parray;
    HRESULT hr = S_OK;
    LONG idx = 0;
	LONG count = 0;
    LONG idx2 = 0;
	LONG count2 = 0;
    if (mConf)
    {
        delete mConf;
    }
    mConf = new Config;
	if(SafeArrayGetDim(parrKey) == 1 && SafeArrayGetDim(parrValues) == 1 &&
        SafeArrayGetLBound(parrKey, 1, &idx) == S_OK && 
        SafeArrayGetUBound(parrKey, 1, &count) == S_OK &&
        SafeArrayGetLBound(parrValues, 1, &idx2) == S_OK &&
        SafeArrayGetUBound(parrValues, 1, &count2) == S_OK &&
        idx == idx2 && count == count2)
	{
        
 
		for(LONG i = idx; i <= count; i++)
		{
			void *key = NULL;
            void *value = NULL;
			if(SafeArrayGetElement(parrKey, &i,static_cast<void *>(&key)) != S_OK ||
               SafeArrayGetElement(parrValues, &i,static_cast<void *>(&value)) != S_OK  )
			{	
                hr = E_INVALIDARG;
                break;
            }
			BSTR strKey = (BSTR)key;
 			BSTR strValue = (BSTR)value;
			if (strKey && strValue)
			{
                CStringA strK(strKey);//??
                CStringA strV(strValue);//??
                mConf->add(strK.GetString(), strV.GetString());
			}

		}
 
	}
    else
    {
        hr = E_INVALIDARG;
    }
    mType = type;
    if (hr != S_OK)
    {
        delete mConf;
        mConf = NULL;
    }
	return hr;
}
STDMETHODIMP CConfigOpt::FromJSON(LONG type, BSTR json)
{
    if (json == NULL)
    {
        return E_FAIL;
    }
    mType = type; 

    if (mConf)
    {
        delete mConf;
    }
    mConf = new Config;
    CStringA strK(json);//??
    mConf->fromJSON(strK.GetString());
    return S_OK;
}

STDMETHODIMP CConfigOpt::FromXML(LONG type, BSTR xml)
{
    if (xml == NULL)
    {
        return E_FAIL;
    }
    mType = type; 

    if (mConf)
    {
        delete mConf;
    }
    mConf = new Config;
    CStringA strK(xml);//??
 
    std::stringstream buf( strK.GetString() );
    Config docConfig;
    docConfig.fromXML(buf);
    switch(type)
    {
    case MODELLAYEROPT:

        *mConf = docConfig.child("model");    
        break;
    case IMAGELAYEROPT:
        *mConf = docConfig.child("image");    
        break;
    case ELEVATIONLAYEROPT:
        *mConf = docConfig.child("elevation");    
        break;
    default:
        break;
    }
    return S_OK;
}
