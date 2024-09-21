/*
============================================================================
Name : 2.c
Author : Eshwar chawda
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.
Date: 24th August, 2024.
============================================================================
*/
#include<stdio.h>
int main(){
    while(1){
        
    }
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/2$ ./2 &
[1] 7629
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/2$ cd proc
bash: cd: proc: No such file or directory
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/2$ cd /proc
eshwar@eshwar-Lenovo-V14-IIL:/proc$ ls
1     165   1845  2134  22    2486  3     439   5431  64    6744  718   764         consoles       key-users      schedstat
1121  166   1851  2135  222   2493  30    44    5605  6466  68    72    7657        cpuinfo        kmsg           scsi
1128  1694  19    2136  223   2526  32    46    57    6489  6801  721   772         crypto         kpagecgroup    self
1138  1696  1932  2140  23    2531  33    47    5777  6498  6818  723   80          devices        kpagecount     slabinfo
1190  1699  1933  2143  2315  2568  34    474   58    65    6819  729   811         diskstats      kpageflags     softirqs
12    17    1949  2145  2318  2587  3428  48    5844  6530  6888  73    830         dma            latency_stats  stat
120   1724  1955  2148  2325  26    35    49    5873  66    6897  730   833         driver         loadavg        swaps
1266  1733  1958  2151  2357  2605  350   5     59    6642  6907  7313  835         dynamic_debug  locks          sys
13    1737  1991  2154  2364  2625  36    50    6     6685  6924  7396  853         execdomains    mdstat         sysrq-trigger
1301  1748  2     2156  2368  2670  374   501   60    6691  6938  7409  9           fb             meminfo        sysvipc
14    1753  20    2157  2373  2679  38    5021  61    6692  6949  7425  902         filesystems    misc           thread-self
148   1757  2004  2160  2385  27    39    51    611   6694  7     744   96          fs             modules        timer_list
15    1759  2005  2161  2392  2725  4     513   6143  6696  7048  7441  acpi        interrupts     mounts         tty
150   1765  2084  2164  24    2728  40    52    616   67    7073  7457  asound      iomem          mtd            uptime
156   1767  2099  2169  2403  2741  4031  522   62    6702  71    7463  bootconfig  ioports        mtrr           version
157   1794  21    2176  2404  275   41    524   621   6703  713   759   buddyinfo   irq            net            version_signature
159   18    2107  2181  2412  2777  42    525   63    6705  714   762   bus         kallsyms       pagetypeinfo   vmallocinfo
16    1806  2116  2185  2437  28    427   53    6322  6731  715   7629  cgroups     kcore          partitions     vmstat
162   1813  2133  2192  2446  29    430   54    6393  6734  7175  763   cmdline     keys           pressure       zoneinfo
eshwar@eshwar-Lenovo-V14-IIL:/proc$ cd 7629
eshwar@eshwar-Lenovo-V14-IIL:/proc/7629$ ls -ltr
total 0
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 stat
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 cmdline
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 statm
-r--------  1 eshwar eshwar 0 Aug 30 14:58 io
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 wchan
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 uid_map
-rw-rw-rw-  1 eshwar eshwar 0 Aug 30 14:58 timerslack_ns
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 timers
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 timens_offsets
dr-xr-xr-x  3 eshwar eshwar 0 Aug 30 14:58 task
-r--------  1 eshwar eshwar 0 Aug 30 14:58 syscall
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 status
-r--------  1 eshwar eshwar 0 Aug 30 14:58 stack
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 smaps_rollup
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 smaps
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 setgroups
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 sessionid
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 schedstat
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 sched
lrwxrwxrwx  1 eshwar eshwar 0 Aug 30 14:58 root -> /
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 projid_map
-r--------  1 eshwar eshwar 0 Aug 30 14:58 personality
-r--------  1 eshwar eshwar 0 Aug 30 14:58 patch_state
-r--------  1 eshwar eshwar 0 Aug 30 14:58 pagemap
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 oom_score_adj
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 oom_score
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 oom_adj
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 numa_maps
dr-x--x--x  2 eshwar eshwar 0 Aug 30 14:58 ns
dr-xr-xr-x 59 eshwar eshwar 0 Aug 30 14:58 net
-r--------  1 eshwar eshwar 0 Aug 30 14:58 mountstats
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 mounts
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 mountinfo
-rw-------  1 eshwar eshwar 0 Aug 30 14:58 mem
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 maps
dr-x------  2 eshwar eshwar 0 Aug 30 14:58 map_files
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 loginuid
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 limits
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 latency
-r--------  1 eshwar eshwar 0 Aug 30 14:58 ksm_stat
-r--------  1 eshwar eshwar 0 Aug 30 14:58 ksm_merging_pages
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 gid_map
dr-xr-xr-x  2 eshwar eshwar 0 Aug 30 14:58 fdinfo
dr-x------  2 eshwar eshwar 3 Aug 30 14:58 fd
lrwxrwxrwx  1 eshwar eshwar 0 Aug 30 14:58 exe -> /home/eshwar/Desktop/SS_ass/2/2
-r--------  1 eshwar eshwar 0 Aug 30 14:58 environ
lrwxrwxrwx  1 eshwar eshwar 0 Aug 30 14:58 cwd -> /home/eshwar/Desktop/SS_ass/2
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 cpuset
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 cpu_resctrl_groups
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 coredump_filter
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 comm
--w-------  1 eshwar eshwar 0 Aug 30 14:58 clear_refs
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 cgroup
-r--------  1 eshwar eshwar 0 Aug 30 14:58 auxv
-rw-r--r--  1 eshwar eshwar 0 Aug 30 14:58 autogroup
dr-xr-xr-x  2 eshwar eshwar 0 Aug 30 14:58 attr
-r--r--r--  1 eshwar eshwar 0 Aug 30 14:58 arch_status
eshwar@eshwar-Lenovo-V14-IIL:/proc/7629$ ^C
eshwar@eshwar-Lenovo-V14-IIL:/proc/7629$ 


*/
