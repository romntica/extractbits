extractbits
-----------

extract bits field with given bit offset from raw bytes

ex)
<code>
         bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0
byte 0  |      Header       |  length |  field1 |
        -----------------------------------------
byte 1  |  field2                          | f3 |
        -----------------------------------------
byte 2  |         f3             |  field4      |
        -----------------------------------------
byte 3  |               field4                  |
        -----------------------------------------
byte 4  | field4   |       field5               |
        -----------------------------------------

    Header = extractByte(data, 0, 7, 4); // byteOffset 0, bitOffset 7, bitLength=4
    length = extractByte(data, 0, 3, 2);
    field1 = extractByte(data, 0, 1, 2);
    field2 = extractByte(data, 1, 7, 6);
    f3 = extractByte(data, 1, 0, 6);
    field4 = extractWord(data, 2, 2, 12);
    field5 = extractWord(data, 4, 5, 6);
</code>


