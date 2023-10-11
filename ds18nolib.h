int8_t dallas(char x) {
  OneWire ds(x);
  byte data[2];
  int16_t result;
  ds.reset();
  ds.write(0xCC);
  ds.write(0xBE);
  data[0] = ds.read();
  data[1] = ds.read();
  result = (data[1] << 8) | data[0];
  result >>= 4; if (data[1] & 128)result |= 61440;
  if (data[0] & 8)++result;
  ds.reset();
  ds.write(0xCC);
  ds.write(0x44, 1);
  return result;
}
