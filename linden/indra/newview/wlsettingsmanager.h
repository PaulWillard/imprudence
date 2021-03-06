/** 
 * @file wlfloaterwindlightsend.h
 * @brief WLFloaterWindLightSend class definition
 *
 * $LicenseInfo:firstyear=2007&license=viewergpl$
 * 
 * Copyright (c) 2007-2009, Linden Research, Inc.
 * 
 * Second Life Viewer Source Code
 * The source code in this file ("Source Code") is provided by Linden Lab
 * to you under the terms of the GNU General Public License, version 2.0
 * ("GPL"), unless you have obtained a separate licensing agreement
 * ("Other License"), formally executed by you and Linden Lab.  Terms of
 * the GPL can be found in doc/GPL-license.txt in this distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/gplv2
 * 
 * There are special exceptions to the terms and conditions of the GPL as
 * it is applied to this Source Code. View the full text of the exception
 * in the file doc/FLOSS-exception.txt in this software distribution, or
 * online at
 * http://secondlifegrid.net/programs/open_source/licensing/flossexception
 * 
 * By copying, modifying or distributing this software, you acknowledge
 * that you have read and understood your obligations described above,
 * and agree to abide by those obligations.
 * 
 * ALL LINDEN LAB SOURCE CODE IS PROVIDED "AS IS." LINDEN LAB MAKES NO
 * WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY,
 * COMPLETENESS OR PERFORMANCE.
 * $/LicenseInfo$
 */

/*
 * Menu for adjusting the atmospheric settings of the world
 */

#ifndef WINDLIGHTSETTINGSMANAGER_H
#define WINDLIGHTSETTINGSMANAGER_H

#include <string>
#include "llwlparamset.h"
#include "llwaterparamset.h"
#include "lluuid.h"

class LLSD;
class LLTimer;
class LLUUID;
class LLWaterParamSet;
class LLWLParamSet;


/// Menuing system for all of windlight's functionality
class WLSettingsManager
{
public:

	static LLTimer* wlIgnoreTimer;
	static bool wlIgnoreRegion;

	// Called after the user has entered a new region, to reset the
	// "ignore while in this region" state.
	static void wlresetRegion();

	static void Apply( LLWLParamSet* Sky, LLWaterParamSet* Water, LLUUID* WaterNormal );

	// Callback when the user interacts with the notification.
	static bool wlapplyCallback(const LLSD& notification,
	                          const LLSD& response);

	static LLWaterParamSet* mWater;
	static LLWLParamSet* mSky;
	static LLUUID* mWaterNormal;

private:
	static void Apply();

	// The name of the water preset where the region settings are stored.
	static const std::string wlWaterPresetName;

	// The name of the sky preset where the region settings are stored.
	static const std::string wlSkyPresetName;

	// Restart the timer for temporarily ignoring settings.
	static void wlrestartIgnoreTimer();

	// Returns true if the ignore timer has expired (i.e. new settings
	// should not be ignored anymore).
	static bool wlignoreTimerHasExpired();
};
#endif