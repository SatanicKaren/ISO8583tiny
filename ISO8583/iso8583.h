#ifndef iso8583_h
#define iso8583_h

typedef struct
{
    char MTI[5];
    unsigned char Bitmap[8];
    char field_2[20];
    char field_3[7];
    char field_4[13];
    char field_5[13];
    char field_6[13];
    char field_7[11];
    char field_8[9];
    char field_9[9];
    char field_10[9];
    char field_11[7];
    char field_12[7];
    char field_13[5];
    char field_14[5];

} iso8583_Message;
typedef struct
{
    const int Fields_length[15];
} iso8583_Field_Length;

void Set_bitmap(unsigned char *bitmap, int field_number);
int is_Field_Present(const unsigned char bitmap, int field);
void init_iso8583(iso8583_Message *msg);
#endif