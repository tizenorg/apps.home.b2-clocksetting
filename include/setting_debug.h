/*
 * Copyright (c) 2010 Samsung Electronics, Inc.
 * All rights reserved.
 *
 * This software is a confidential and proprietary information
 * of Samsung Electronics, Inc. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Samsung Electronics.
 */
#define _DLOG_USED
#ifdef 	_DLOG_USED

#include <dlog.h>

#ifdef LOG_TAG
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
