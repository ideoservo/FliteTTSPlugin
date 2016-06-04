// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "IFliteTTSPlugin.h"


// Disable crazy warnings that claim that standard C library is "deprecated".
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif

#pragma push_macro("ARRAY_COUNT")
#undef ARRAY_COUNT

#include "../../../ThirdParty/flite/include/flite.h"

extern "C" {
	cst_voice *register_cmu_us_rms(const char *voxdir);
	void unregister_cmu_us_rms(cst_voice *v);
	cst_voice *register_cmu_us_slt(const char *voxdir);
	void unregister_cmu_us_slt(cst_voice *v);
}

#pragma pop_macro("ARRAY_COUNT")

#ifdef _MSC_VER
#pragma warning(pop)
#endif
