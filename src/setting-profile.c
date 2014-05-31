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
#include "setting-profile.h"
#include "util.h"

/* profile(s-health) */
void _create_profile(void *data, Evas_Object *obj, void *event_info)
{
	appdata *ad = data;
	if( ad == NULL )
	{
		DBG("%s", "_create_profile - appdata is null");
		return;
	}

	service_h service;
	service_create(&service);
	service_set_package(service, PROFILE_APP_ID);
	service_set_operation(service, PROFILE_OP_ID);
	service_send_launch_request(service, NULL, NULL);
	service_destroy(service);
}

