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
#define _DLOG_USED
#ifdef 	_DLOG_USED

#include <dlog.h>

#ifdef LOG_TAG	16
#undef LOG_TAG
#define LOG_TAG "W-SETTING"
#endif

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

#endif
