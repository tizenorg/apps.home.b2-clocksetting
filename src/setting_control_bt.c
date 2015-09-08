/*
 *  Copyright (c) 2014 Samsung Electronics Co., Ltd.
 *
 *  Licensed under the Flora License, Version 1.0 (the License);
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://floralicense.org/license/
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an AS IS BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */
#include "setting_control_bt.h"
#include "setting_debug.h"
#include <stdio.h>

int hf_is_connected()
{
	int ret;
	int i;
	GPtrArray *dev_list = NULL;
	bluetooth_device_info_t *dev;
	gboolean is_connected = FALSE;

	dev_list = g_ptr_array_new();
	if (dev_list == NULL) {
		printf("Setting - g_ptr_array_new is failed\n");
		return FALSE;
	}

	ret = bluetooth_get_bonded_device_list(&dev_list);
	if (ret != BLUETOOTH_ERROR_NONE) {
		printf("Setting - bluetooth_get_bonded_device_list is failed 0x%X\n", ret);
		g_ptr_array_free(dev_list, TRUE);
		return FALSE;
	}

	for (i = 0; i < dev_list->len; i++) {
		is_connected = FALSE;

		dev = g_ptr_array_index(dev_list, i);
		if (dev  == NULL) {
			printf("Setting - Invalid bluetooth device\n");
			break;
		}

		ret = bluetooth_is_device_connected(&dev->device_address,
											BLUETOOTH_HFG_SERVICE, &is_connected);
		if (ret == BLUETOOTH_ERROR_NONE && is_connected) {
			break;
		}
	}

	g_ptr_array_foreach(dev_list, (GFunc)g_free, NULL);
	g_ptr_array_free(dev_list, TRUE);

	DBG("Setting - connected? %d", is_connected);

	return is_connected;
}
