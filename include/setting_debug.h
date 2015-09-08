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
#define _DLOG_USED
#ifdef 	_DLOG_USED

#include <dlog.h>

#ifdef LOG_TAG
#undef LOG_TAG
#define LOG_TAG "W-SETTING"
#endif

#define SETTING_RETURN_SUCCESS 1
#define SETTING_RETURN_FAIL -1

#define DBG(fmt , args...) \
	do { \
		LOGD("[%s : %d] "fmt"", __func__, __LINE__, ##args); \
	} while (0)

#define INFO(fmt , args...) \
	do { \
		LOGI("[%s : %d] "fmt"", __func__, __LINE__, ##args); \
	} while (0)

#define WARN(fmt , args...) \
	do { \
		LOGI("[%s : %d] "fmt"", __func__, __LINE__, ##args); \
	} while (0)

#define ERR(fmt , args...) \
	do { \
		LOGI("[%s : %d] "fmt"", __func__, __LINE__, ##args); \
	} while (0)


#define __FREE(del, arg) do { \
		if(arg) { \
			del((void *)(arg)); /*cast any argument to (void*) to avoid build warring*/\
			arg = NULL; \
		} \
	} while (0);

#define FREE(arg) __FREE(free, arg)

#define setting_retvm_if(expr, val, fmt, arg...) do { \
		if(expr) { \
			ERR(fmt, ##arg); \
			return (val); \
		} \
	} while (0);

#define setting_retm_if(expr, fmt, arg...) do { \
		if(expr) { \
			ERR(fmt, ##arg); \
			return; \
		} \
	} while (0);

#endif
