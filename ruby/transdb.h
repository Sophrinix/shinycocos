rb_declare_transcoder("Big5", "UTF-8", "big5");
rb_declare_transcoder("UTF-8", "Big5", "big5");
rb_declare_transcoder("GB2312", "UTF-8", "chinese");
rb_declare_transcoder("GB12345", "UTF-8", "chinese");
rb_declare_transcoder("UTF-8", "GB2312", "chinese");
rb_declare_transcoder("UTF-8", "GB12345", "chinese");
rb_declare_transcoder("", "amp_escape", "escape");
rb_declare_transcoder("", "xml_text_escape", "escape");
rb_declare_transcoder("", "xml_attr_content_escape", "escape");
rb_declare_transcoder("", "xml_attr_quote", "escape");
rb_declare_transcoder("GB18030", "UTF-8", "gb18030");
rb_declare_transcoder("UTF-8", "GB18030", "gb18030");
rb_declare_transcoder("GBK", "UTF-8", "gbk");
rb_declare_transcoder("UTF-8", "GBK", "gbk");
rb_declare_transcoder("ISO-2022-JP", "stateless-ISO-2022-JP", "iso2022");
rb_declare_transcoder("stateless-ISO-2022-JP", "ISO-2022-JP", "iso2022");
rb_declare_transcoder("stateless-ISO-2022-JP", "EUC-JP", "iso2022");
rb_declare_transcoder("EUC-JP", "stateless-ISO-2022-JP", "iso2022");
rb_declare_transcoder("EUC-JP", "Shift_JIS", "japanese");
rb_declare_transcoder("Shift_JIS", "EUC-JP", "japanese");
rb_declare_transcoder("EUC-JP", "UTF-8", "japanese_euc");
rb_declare_transcoder("eucJP-ms", "UTF-8", "japanese_euc");
rb_declare_transcoder("CP51932", "UTF-8", "japanese_euc");
rb_declare_transcoder("UTF-8", "EUC-JP", "japanese_euc");
rb_declare_transcoder("UTF-8", "eucJP-ms", "japanese_euc");
rb_declare_transcoder("UTF-8", "CP51932", "japanese_euc");
rb_declare_transcoder("Shift_JIS", "UTF-8", "japanese_sjis");
rb_declare_transcoder("Windows-31J", "UTF-8", "japanese_sjis");
rb_declare_transcoder("UTF-8", "Shift_JIS", "japanese_sjis");
rb_declare_transcoder("UTF-8", "Windows-31J", "japanese_sjis");
rb_declare_transcoder("UTF-8", "EUC-KR", "korean");
rb_declare_transcoder("EUC-KR", "UTF-8", "korean");
rb_declare_transcoder("UTF-8", "CP949", "korean");
rb_declare_transcoder("CP949", "UTF-8", "korean");
rb_declare_transcoder("US-ASCII", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "US-ASCII", "single_byte");
rb_declare_transcoder("ASCII-8BIT", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ASCII-8BIT", "single_byte");
rb_declare_transcoder("ISO-8859-1", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-1", "single_byte");
rb_declare_transcoder("ISO-8859-2", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-2", "single_byte");
rb_declare_transcoder("ISO-8859-3", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-3", "single_byte");
rb_declare_transcoder("ISO-8859-4", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-4", "single_byte");
rb_declare_transcoder("ISO-8859-5", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-5", "single_byte");
rb_declare_transcoder("ISO-8859-6", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-6", "single_byte");
rb_declare_transcoder("ISO-8859-7", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-7", "single_byte");
rb_declare_transcoder("ISO-8859-8", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-8", "single_byte");
rb_declare_transcoder("ISO-8859-9", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-9", "single_byte");
rb_declare_transcoder("ISO-8859-10", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-10", "single_byte");
rb_declare_transcoder("ISO-8859-11", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-11", "single_byte");
rb_declare_transcoder("ISO-8859-13", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-13", "single_byte");
rb_declare_transcoder("ISO-8859-14", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-14", "single_byte");
rb_declare_transcoder("ISO-8859-15", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "ISO-8859-15", "single_byte");
rb_declare_transcoder("WINDOWS-874", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "WINDOWS-874", "single_byte");
rb_declare_transcoder("WINDOWS-1250", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "WINDOWS-1250", "single_byte");
rb_declare_transcoder("WINDOWS-1251", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "WINDOWS-1251", "single_byte");
rb_declare_transcoder("WINDOWS-1252", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "WINDOWS-1252", "single_byte");
rb_declare_transcoder("WINDOWS-1253", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "WINDOWS-1253", "single_byte");
rb_declare_transcoder("WINDOWS-1254", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "WINDOWS-1254", "single_byte");
rb_declare_transcoder("WINDOWS-1255", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "WINDOWS-1255", "single_byte");
rb_declare_transcoder("WINDOWS-1256", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "WINDOWS-1256", "single_byte");
rb_declare_transcoder("WINDOWS-1257", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "WINDOWS-1257", "single_byte");
rb_declare_transcoder("IBM437", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM437", "single_byte");
rb_declare_transcoder("IBM775", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM775", "single_byte");
rb_declare_transcoder("IBM852", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM852", "single_byte");
rb_declare_transcoder("IBM855", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM855", "single_byte");
rb_declare_transcoder("IBM857", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM857", "single_byte");
rb_declare_transcoder("IBM860", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM860", "single_byte");
rb_declare_transcoder("IBM861", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM861", "single_byte");
rb_declare_transcoder("IBM862", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM862", "single_byte");
rb_declare_transcoder("IBM863", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM863", "single_byte");
rb_declare_transcoder("IBM865", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM865", "single_byte");
rb_declare_transcoder("IBM866", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM866", "single_byte");
rb_declare_transcoder("IBM869", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "IBM869", "single_byte");
rb_declare_transcoder("MACCROATIAN", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "MACCROATIAN", "single_byte");
rb_declare_transcoder("MACCYRILLIC", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "MACCYRILLIC", "single_byte");
rb_declare_transcoder("MACGREEK", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "MACGREEK", "single_byte");
rb_declare_transcoder("MACICELAND", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "MACICELAND", "single_byte");
rb_declare_transcoder("MACROMAN", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "MACROMAN", "single_byte");
rb_declare_transcoder("MACROMANIA", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "MACROMANIA", "single_byte");
rb_declare_transcoder("MACTURKISH", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "MACTURKISH", "single_byte");
rb_declare_transcoder("MACUKRAINE", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "MACUKRAINE", "single_byte");
rb_declare_transcoder("KOI8-U", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "KOI8-U", "single_byte");
rb_declare_transcoder("KOI8-R", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "KOI8-R", "single_byte");
rb_declare_transcoder("TIS-620", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "TIS-620", "single_byte");
rb_declare_transcoder("CP850", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "CP850", "single_byte");
rb_declare_transcoder("CP852", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "CP852", "single_byte");
rb_declare_transcoder("CP855", "UTF-8", "single_byte");
rb_declare_transcoder("UTF-8", "CP855", "single_byte");
rb_declare_transcoder("UTF-16BE", "UTF-8", "utf_16_32");
rb_declare_transcoder("UTF-8", "UTF-16BE", "utf_16_32");
rb_declare_transcoder("UTF-16LE", "UTF-8", "utf_16_32");
rb_declare_transcoder("UTF-8", "UTF-16LE", "utf_16_32");
rb_declare_transcoder("UTF-32BE", "UTF-8", "utf_16_32");
rb_declare_transcoder("UTF-8", "UTF-32BE", "utf_16_32");
rb_declare_transcoder("UTF-32LE", "UTF-8", "utf_16_32");
rb_declare_transcoder("UTF-8", "UTF-32LE", "utf_16_32");
