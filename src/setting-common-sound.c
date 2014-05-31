/*
 * Copyright (c) 2000 - 2013 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
/*
 * setting-common-sound.c
 *
 *  Created on: Oct 16, 2013
 *      Author: min-hoyun
 */

#include <vconf.h>
#include <vconf-keys.h>

#include "setting-common-sound.h"
#include "util.h"

static player_h player;
static int is_player_created = 0;
static sound_type_e _sound_type;


/**
 * @return zero on successful
 */

int get_sound_mode()
{
	int mode = 1;
	int is_enable_sound   = 0;
	int is_enable_vibrate = 0;

	vconf_get_bool(VCONFKEY_SETAPPL_SOUND_STATUS_BOOL, &is_enable_sound);
	vconf_get_bool(VCONFKEY_SETAPPL_VIBRATION_STATUS_BOOL, &is_enable_vibrate);

	if( is_enable_sound && !is_enable_vibrate )	// sound mode
	{
		mode = SOUND_MODE_SOUND;
	}
	else if( !is_enable_sound && is_enable_vibrate ) // vibration mode
	{
		mode = SOUND_MODE_VIBRATE;
	}
	else if( !is_enable_sound && !is_enable_vibrate ) // mute
	{
		mode = SOUND_MODE_MUTE;
	}
	return mode;
}

static void _profile_player_prepare_cb(void *data)
{
	DBG("Player is prepared. Start player");

	if( !is_created_player() )
	{
		DBG("Player start cancel!!");
		return;
	}

	if(player != NULL)
	{
		player_state_e play_state;
		player_get_state(player, &play_state);
		if (play_state == PLAYER_STATE_PAUSED || play_state == PLAYER_STATE_READY) {
			int err = 0;
			err = player_start(player);
			if (err != PLAYER_ERROR_NONE) {	/* if directly return error.. */
				DBG("Setting - player_start [%d]", err);
				player_unprepare(player);
				player_destroy(player);
				is_player_created = 0;
				return;
			}
		}
		else{
			DBG("Player state = %d. do not start", play_state);
		}
	}
}

int is_player_paused()
{
	int ret = FALSE;
	player_state_e state = -1;
	player_get_state(player, &state);
	if (state != PLAYER_STATE_PLAYING)
	{
		DBG("Setting - player is paused!!");
		ret = TRUE;
	}
	return ret;
}

static int _profile_restart_player(void *data, char *ringtone_file, sound_type_e sound_type, int prelistening_enable)
{
	player_state_e state = -1;
	int ret = TRUE;
	int prev_behavior = 0;	/*  instead of do_while(0) and break */

	player_get_state(player, &state);
	if (state == PLAYER_STATE_PLAYING) {
		if (player_stop(player) != PLAYER_ERROR_NONE) {
			DBG("Setting - mm player stop failed");
			ret = -1;
			prev_behavior++;	/*  instead of do_while(0) and break */
		}
	}

	if ((prev_behavior == 0) && (player_unprepare(player) != PLAYER_ERROR_NONE)) {
		DBG("Setting - mm player unrealize failed");
		ret = -1;
		prev_behavior++;	/*  instead of do_while(0) and break */
	}

	if (prev_behavior == 0) {
		int err= 0;
		err = player_set_uri(player, ringtone_file);
		if (err != PLAYER_ERROR_NONE) {
			DBG("Setting - error to set attribute---profile_uri[%d]", err);
			player_destroy(player);
			is_player_created = 0;
			return err;
		}

		err = player_prepare_async(player, _profile_player_prepare_cb, NULL);
		if (err != PLAYER_ERROR_NONE) {
			DBG("Setting - realizing the player handle failed[%d]", err);
			player_destroy(player);
			is_player_created = 0;
			return err;
		}
	}
	return ret;
}

int profile_play_sound(void *data, void *cb, char *ringtone_file, float vol, sound_type_e sound_type, int prelistening_enable)
{
	DBG("Setting - profile_play_sound is started. path: %s", ringtone_file);
	DBG("Setting - profile_play_sound is creating.");

	int err = 0;
	err = player_create(&player);
	if( err != PLAYER_ERROR_NONE )
	{
		DBG("Setting - creating the player handle failed[%d]", err);
		return NULL;
	}

	DBG("Setting - profile_play_sound is setting sound type.");

	err = player_set_sound_type(player, sound_type);
	if (err != PLAYER_ERROR_NONE) {
		DBG("Setting - error to set sound_type[%d]", err);
		player_destroy(player);
		is_player_created = 0;
		return err;
	}

	DBG("Setting - profile_play_sound is setting uri.");

	err = player_set_uri(player, ringtone_file);
	if (err != PLAYER_ERROR_NONE) {
		DBG("Setting - error to set attribute---profile_uri[%d]", err);
		player_destroy(player);
		is_player_created = 0;
		return err;
	}

	DBG("Setting - profile_play_sound is preparing.");

	//err = player_prepare(player);
	err = player_prepare_async(player, _profile_player_prepare_cb, NULL);
	if (err != PLAYER_ERROR_NONE) {
		DBG("Setting - realizing the player handle failed[%d]", err);
		player_destroy(player);
		is_player_created = 0;
		return err;
	}

	DBG("Setting - waiting..");

	_sound_type = sound_type;

	is_player_created = 1;

	return err;
}

int _profile_stop_sound(void *data)
{
	player_state_e state = -1;
	int ret = TRUE;
	int prev_behavior = 0;	/*  instead of do_while(0) and break */

	player_get_state(player, &state);
	if (state == PLAYER_STATE_PLAYING) {
		if (player_stop(player) != PLAYER_ERROR_NONE) {
			DBG("Setting - mm player stop failed");
			ret = -1;
			prev_behavior++;	/*  instead of do_while(0) and break */
		}
	}

	//player_unset_completed_cb(*player);
	//player_unset_interrupted_cb(*player);

	if ((prev_behavior == 0) && (player_unprepare(player) != PLAYER_ERROR_NONE)) {
		DBG("Setting - mm player unrealize failed");
		ret = -1;
		prev_behavior++;	/*  instead of do_while(0) and break */
	}

	if ((prev_behavior == 0) && (player_destroy(player) != PLAYER_ERROR_NONE)) {
		DBG("Setting - mm player destroy failed");
		ret = -1;
	}

	is_player_created = 0;

	return ret;
}

int is_created_player()
{
	return is_player_created;
}

void set_looping(int enable)
{
	if(is_created_player())
		player_set_looping(player, enable);
	else
		ERR("player is not created!!");
}

int _close_player(void *data, sound_type_e type)
{
	if ( is_created_player() )
	{
		if (_profile_stop_sound(data))
		{
			is_player_created = 0;
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;
}

void play_sound(char * file_path, float volume, sound_type_e sound_type)
{
	DBG("Setting - profile_play_sound function start ...");
	if( !is_created_player() )
	{
		DBG("Setting - profile_play_sound)");
		profile_play_sound(NULL, NULL, file_path, volume, sound_type, TRUE);
		set_looping(TRUE);
	}
	else
	{
		_profile_restart_player(NULL, file_path, sound_type, TRUE);
	}
}

void play_sound_for_sound_mode(char * file_path, float volume, sound_type_e sound_type)
{
	DBG("Setting - play_sound_for_sound_mode function start ...");
	if( !is_created_player() )
	{
		DBG("Setting - play_sound_for_sound_mode)");
		profile_play_sound(NULL, NULL, file_path, volume, sound_type, FALSE);
		set_looping(TRUE);
	}
	else
	{
		_profile_restart_player(NULL, file_path, sound_type, FALSE);
	}
}
