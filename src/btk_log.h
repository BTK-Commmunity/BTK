#ifndef BTK_LOG_H
#define BTK_LOG_H


#include <stdio.h>


// Thanks to https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a for the color defines

// Regular text
#define BTK_LOG_COLOR_BLK "\e[0;30m"
#define BTK_LOG_COLOR_RED "\e[0;31m"
#define BTK_LOG_COLOR_GRN "\e[0;32m"
#define BTK_LOG_COLOR_YEL "\e[0;33m"
#define BTK_LOG_COLOR_BLU "\e[0;34m"
#define BTK_LOG_COLOR_MAG "\e[0;35m"
#define BTK_LOG_COLOR_CYN "\e[0;36m"
#define BTK_LOG_COLOR_WHT "\e[0;37m"

// Regular bold text
#define BTK_LOG_COLOR_BBLK "\e[1;30m"
#define BTK_LOG_COLOR_BRED "\e[1;31m"
#define BTK_LOG_COLOR_BGRN "\e[1;32m"
#define BTK_LOG_COLOR_BYEL "\e[1;33m"
#define BTK_LOG_COLOR_BBLU "\e[1;34m"
#define BTK_LOG_COLOR_BMAG "\e[1;35m"
#define BTK_LOG_COLOR_BCYN "\e[1;36m"
#define BTK_LOG_COLOR_BWHT "\e[1;37m"

// Regular underline text
#define BTK_LOG_COLOR_UBLK "\e[4;30m"
#define BTK_LOG_COLOR_URED "\e[4;31m"
#define BTK_LOG_COLOR_UGRN "\e[4;32m"
#define BTK_LOG_COLOR_UYEL "\e[4;33m"
#define BTK_LOG_COLOR_UBLU "\e[4;34m"
#define BTK_LOG_COLOR_UMAG "\e[4;35m"
#define BTK_LOG_COLOR_UCYN "\e[4;36m"
#define BTK_LOG_COLOR_UWHT "\e[4;37m"

// Regular background
#define BTK_LOG_COLOR_BLKB "\e[40m"
#define BTK_LOG_COLOR_REDB "\e[41m"
#define BTK_LOG_COLOR_GRNB "\e[42m"
#define BTK_LOG_COLOR_YELB "\e[43m"
#define BTK_LOG_COLOR_BLUB "\e[44m"
#define BTK_LOG_COLOR_MAGB "\e[45m"
#define BTK_LOG_COLOR_CYNB "\e[46m"
#define BTK_LOG_COLOR_WHTB "\e[47m"

// High intensity background
#define BTK_LOG_COLOR_BLKHB "\e[0;100m"
#define BTK_LOG_COLOR_REDHB "\e[0;101m"
#define BTK_LOG_COLOR_GRNHB "\e[0;102m"
#define BTK_LOG_COLOR_YELHB "\e[0;103m"
#define BTK_LOG_COLOR_BLUHB "\e[0;104m"
#define BTK_LOG_COLOR_MAGHB "\e[0;105m"
#define BTK_LOG_COLOR_CYNHB "\e[0;106m"
#define BTK_LOG_COLOR_WHTHB "\e[0;107m"

// High intensity text
#define BTK_LOG_COLOR_HBLK "\e[0;90m"
#define BTK_LOG_COLOR_HRED "\e[0;91m"
#define BTK_LOG_COLOR_HGRN "\e[0;92m"
#define BTK_LOG_COLOR_HYEL "\e[0;93m"
#define BTK_LOG_COLOR_HBLU "\e[0;94m"
#define BTK_LOG_COLOR_HMAG "\e[0;95m"
#define BTK_LOG_COLOR_HCYN "\e[0;96m"
#define BTK_LOG_COLOR_HWHT "\e[0;97m"

// Bold high intensity text
#define BTK_LOG_COLOR_BHBLK "\e[1;90m"
#define BTK_LOG_COLOR_BHRED "\e[1;91m"
#define BTK_LOG_COLOR_BHGRN "\e[1;92m"
#define BTK_LOG_COLOR_BHYEL "\e[1;93m"
#define BTK_LOG_COLOR_BHBLU "\e[1;94m"
#define BTK_LOG_COLOR_BHMAG "\e[1;95m"
#define BTK_LOG_COLOR_BHCYN "\e[1;96m"
#define BTK_LOG_COLOR_BHWHT "\e[1;97m"

// Reset
#define BTK_LOG_COLOR_RESET "\e[0m"
#define BTK_LOG_COLOR_CRESET "\e[0m"
#define BTK_LOG_COLOR_COLOR_RESET "\e[0m"




#define BTK_LOG_CUSTOM(color, msg, ...) printf(color msg "\n" BTK_LOG_COLOR_RESET, ##__VA_ARGS__)

// Predefined logging macros with default colors
#define BTK_LOG_INFO(msg, ...)    BTK_LOG_CUSTOM(BTK_LOG_COLOR_BGRN, "[INFO] " msg, ##__VA_ARGS__)
#define BTK_LOG_WARN(msg, ...)    BTK_LOG_CUSTOM(BTK_LOG_COLOR_BYEL, "[WARN] " msg, ##__VA_ARGS__)
#define BTK_LOG_ERROR(msg, ...)   BTK_LOG_CUSTOM(BTK_LOG_COLOR_BRED, "[ERROR] " msg, ##__VA_ARGS__)
#define BTK_LOG_DEBUG(msg, ...)   BTK_LOG_CUSTOM(BTK_LOG_COLOR_BCYN, "[DEBUG] " msg, ##__VA_ARGS__)
#define BTK_LOG_FATAL(msg, ...)   BTK_LOG_CUSTOM(BTK_LOG_COLOR_BHRED, "[FATAL] " msg, ##__VA_ARGS__)
#endif 