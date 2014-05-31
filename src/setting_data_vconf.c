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
#include "setting_data_vconf.h"
#include "util.h"


void unregister_vconf_changing(const char *vconf, vconf_callback_fn cb)
{
	if (vconf && cb) {
		int ret = vconf_ignore_key_changed(vconf, cb);
		if (ret != 0) {
			DBG("Setting - vconf's changed callback do not unregist");
		}
		else
		{
			DBG("Setting - vconf's changed callback unregisted!!");
		}
	}
}

int register_vconf_changing(const char *vconf, vconf_callback_fn cb, void *data)
{
	int ret = 1;
	if ( vconf && cb )
	{
		if(0 == vconf_notify_key_changed(vconf, cb, data))
		{
			DBG("Setting - vconf's changed callback is registed!");
		}
		else
		{
			DBG("Setting - vconf's changed callback is not registed!");
			ret = 0;
		}
	}
	return ret;
}
