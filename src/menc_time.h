#ifndef JENH_TIME_H
#define JENH_TIME_H

#define Time u64

#define TIME_MIL  (1)
#define TIME_SEC  (100 * TIME_MIL)
#define TIME_MIN  (60  * TIME_SEC)
#define TIME_HR   (60  * TIME_MIN)
#define TIME_DAY  (24  * TIME_HR)

#ifdef _WIN32
typedef struct {
    b8  sleepIsGranular;
    u32 schedulerMs;

    s64 counterFrecuency;
} Time_OS;
#endif

Public void Time_OS_Init(void);
Public void Time_OS_Cleanup(void);

Public Time Time_Get(void);

//Public s32 OS_Get_Refresh_Rate(void);

Public u64 Time_CPU_Counter(void);

Public s64 Time_OS_Counter(void);
Public f32 Time_OS_Seconds_Elapsed(s64 begin, s64 end);

Public f32 Time_Sec_To_Ms(f32 secs);

// WIN32
Public Time OS_FILETIME_To_Time(FILETIME inFileTime);

#endif // JENH_TIME_H
