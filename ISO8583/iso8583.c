#include <stdio.h>
#include <string.h>
#include "iso8583.h"

void Set_bitmap(unsigned char *bitmap, int field_number)
{
    int byte_index = (field_number - 1) / 8;
    int bit_index = 7 - ((field_number - 1) % 8);
    bitmap[byte_index] |= (1 << bit_index);
}
int is_Field_Present(const unsigned char *bitmap, int field_number)
{
    int byte_index = (field_number - 1) / 8;
    int bit_index = 7 - ((field_number - 1) % 8);
    return (bitmap[byte_index] >> bit_index) & 1;
}
void init_iso8583(iso8583_Message *msg)
{
    // length initalizor
    const iso8583_Field_Length Fields_length = {.Fields_length = {
                                                    [0] = sizeof(msg->MTI) - 1,
                                                    [1] = sizeof(msg->Bitmap) - 1,
                                                    [2] = sizeof(msg->field_2) - 1,
                                                    [3] = sizeof(msg->field_3) - 1,
                                                    [4] = sizeof(msg->field_4) - 1,
                                                    [5] = sizeof(msg->field_5) - 1,
                                                    [6] = sizeof(msg->field_6) - 1,
                                                    [7] = sizeof(msg->field_7) - 1,
                                                    [8] = sizeof(msg->field_8) - 1,
                                                    [9] = sizeof(msg->field_9) - 1,
                                                    [10] = sizeof(msg->field_10) - 1,
                                                    [11] = sizeof(msg->field_11) - 1,
                                                    [12] = sizeof(msg->field_12) - 1,
                                                    [13] = sizeof(msg->field_13) - 1,
                                                    [14] = sizeof(msg->field_14) - 1}};
    // make msg null
    memset(msg->MTI, 0, sizeof(msg->MTI));
    memset(msg->Bitmap, 0, sizeof(msg->Bitmap));
    memset(msg->field_2, 0, sizeof(msg->field_2));
    memset(msg->field_3, 0, sizeof(msg->field_3));
    memset(msg->field_4, 0, sizeof(msg->field_4));
    memset(msg->field_5, 0, sizeof(msg->field_5));
    memset(msg->field_6, 0, sizeof(msg->field_6));
    memset(msg->field_7, 0, sizeof(msg->field_7));
    memset(msg->field_8, 0, sizeof(msg->field_8));
    memset(msg->field_9, 0, sizeof(msg->field_9));
    memset(msg->field_10, 0, sizeof(msg->field_10));
    memset(msg->field_11, 0, sizeof(msg->field_11));
    memset(msg->field_12, 0, sizeof(msg->field_12));
    memset(msg->field_13, 0, sizeof(msg->field_13));
    memset(msg->field_14, 0, sizeof(msg->field_14));
}
