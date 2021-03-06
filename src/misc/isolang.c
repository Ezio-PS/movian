/*
 *  Copyright (C) 2007-2015 Lonelycoder AB
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  This program is also available under a commercial proprietary license.
 *  For more information, contact andreas@lonelycoder.com
 */
#include <stddef.h>
#include <string.h>
#include "isolang.h"

static const isolang_t langtable[] = {
  {"aar", "aa", "Afar, afar"},
  {"abk", "ab", "Abkhazian"},
  {"ace", "", "Achinese"},
  {"ach", "", "Acoli"},
  {"ada", "", "Adangme"},
  {"ady", "", "adyghé"},
  {"afa", "", "Afro-Asiatic (Other)"},
  {"afh", "", "Afrihili"},
  {"afr", "af", "Afrikaans"},
  {"ain", "", "Ainu"},
  {"aka", "ak", "Akan"},
  {"akk", "", "Akkadian"},
  {"alb", "sq", "Albanian"},
  {"ale", "", "Aleut"},
  {"alg", "", "Algonquian languages"},
  {"alt", "", "Southern Altai"},
  {"amh", "am", "Amharic"},
  {"ang", "", "English, Old (ca.450-1100)"},
  {"apa", "", "Apache languages"},
  {"ara", "ar", "Arabic"},
  {"arc", "", "Aramaic"},
  {"arg", "an", "Aragonese"},
  {"arm", "hy", "Armenian"},
  {"arn", "", "Araucanian"},
  {"arp", "", "Arapaho"},
  {"art", "", "Artificial (Other)"},
  {"arw", "", "Arawak"},
  {"asm", "as", "Assamese"},
  {"ast", "", "Asturian, Bable"},
  {"ath", "", "Athapascan languages"},
  {"aus", "", "Australian languages"},
  {"ava", "av", "Avaric"},
  {"ave", "ae", "Avestan"},
  {"awa", "", "Awadhi"},
  {"aym", "ay", "Aymara"},
  {"aze", "az", "Azerbaijani"},
  {"bad", "", "Banda"},
  {"bai", "", "Bamileke languages"},
  {"bak", "ba", "Bashkir"},
  {"bal", "", "Baluchi"},
  {"bam", "bm", "Bambara"},
  {"ban", "", "Balinese"},
  {"baq", "eu", "Basque"},
  {"bas", "", "Basa"},
  {"bat", "", "Baltic (Other)"},
  {"bej", "", "Beja"},
  {"bel", "be", "Belarusian"},
  {"bem", "", "Bemba"},
  {"ben", "bn", "Bengali"},
  {"ber", "", "Berber (Other)"},
  {"bho", "", "Bhojpuri"},
  {"bih", "bh", "Bihari"},
  {"bik", "", "Bikol"},
  {"bin", "", "Bini"},
  {"bis", "bi", "Bislama"},
  {"bla", "", "Siksika"},
  {"bnt", "", "Bantu (Other)"},
  {"bos", "bs", "Bosnian"},
  {"bra", "", "Braj"},
  {"bre", "br", "Breton"},
  {"btk", "", "Batak (Indonesia)"},
  {"bua", "", "Buriat"},
  {"bug", "", "Buginese"},
  {"bul", "bg", "Bulgarian"},
  {"bur", "my", "Burmese"},
  {"byn", "", "Blin"},
  {"cad", "", "Caddo"},
  {"cai", "", "Central American Indian (Other)"},
  {"car", "", "Carib"},
  {"cat", "ca", "Catalan"},
  {"cau", "", "Caucasian (Other)"},
  {"ceb", "", "Cebuano"},
  {"cel", "", "Celtic (Other)"},
  {"cha", "ch", "Chamorro"},
  {"chb", "", "Chibcha"},
  {"che", "ce", "Chechen"},
  {"chg", "", "Chagatai"},
  {"chi", "zh", "Chinese"},
  {"chk", "", "Chuukese"},
  {"chm", "", "Mari"},
  {"chn", "", "Chinook jargon"},
  {"cho", "", "Choctaw"},
  {"chp", "", "Chipewyan"},
  {"chr", "", "Cherokee"},
  {"chu", "cu", "Church Slavic"},
  {"chv", "cv", "Chuvash"},
  {"chy", "", "Cheyenne"},
  {"cmc", "", "Chamic languages"},
  {"cop", "", "Coptic"},
  {"cor", "kw", "Cornish"},
  {"cos", "co", "Corsican"},
  {"cpe", "", "Creoles and pidgins, English based (Other)"},
  {"cpf", "", "Creoles and pidgins, French-based (Other)"},
  {"cpp", "", "Creoles and pidgins, Portuguese-based (Other)"},
  {"cre", "cr", "Cree"},
  {"crh", "", "Crimean Tatar"},
  {"crp", "", "Creoles and pidgins (Other)"},
  {"csb", "", "Kashubian"},
  {"cus", "", "Cushitic (Other)' couchitiques, autres langues"},
  {"cze", "cs", "Czech"},
  {"dak", "", "Dakota"},
  {"dan", "da", "Danish"},
  {"dar", "", "Dargwa"},
  {"day", "", "Dayak"},
  {"del", "", "Delaware"},
  {"den", "", "Slave (Athapascan)"},
  {"dgr", "", "Dogrib"},
  {"din", "", "Dinka"},
  {"div", "dv", "Divehi"},
  {"doi", "", "Dogri"},
  {"dra", "", "Dravidian (Other)"},
  {"dua", "", "Duala"},
  {"dum", "", "Dutch, Middle (ca.1050-1350)"},
  {"dut", "nl", "Dutch"},
  {"dyu", "", "Dyula"},
  {"dzo", "dz", "Dzongkha"},
  {"efi", "", "Efik"},
  {"egy", "", "Egyptian (Ancient)"},
  {"eka", "", "Ekajuk"},
  {"elx", "", "Elamite"},
  {"eng", "en", "English"},
  {"enm", "", "English, Middle (1100-1500)"},
  {"epo", "eo", "Esperanto"},
  {"est", "et", "Estonian"},
  {"ewe", "ee", "Ewe"},
  {"ewo", "", "Ewondo"},
  {"fan", "", "Fang"},
  {"fao", "fo", "Faroese"},
  {"fat", "", "Fanti"},
  {"fij", "fj", "Fijian"},
  {"fil", "", "Filipino"},
  {"fin", "fi", "Finnish"},
  {"fiu", "", "Finno-Ugrian (Other)"},
  {"fon", "", "Fon"},
  {"fre", "fr", "French"},
  {"frm", "", "French, Middle (ca.1400-1600)"},
  {"fro", "", "French, Old (842-ca.1400)"},
  {"fry", "fy", "Frisian"},
  {"ful", "ff", "Fulah"},
  {"fur", "", "Friulian"},
  {"gaa", "", "Ga"},
  {"gay", "", "Gayo"},
  {"gba", "", "Gbaya"},
  {"gem", "", "Germanic (Other)"},
  {"geo", "ka", "Georgian"},
  {"ger", "de", "German"},
  {"gez", "", "Geez"},
  {"gil", "", "Gilbertese"},
  {"gla", "gd", "Gaelic"},
  {"gle", "ga", "Irish"},
  {"glg", "gl", "Galician"},
  {"glv", "gv", "Manx"},
  {"gmh", "", "German, Middle High (ca.1050-1500)"},
  {"goh", "", "German, Old High (ca.750-1050)"},
  {"gon", "", "Gondi"},
  {"gor", "", "Gorontalo"},
  {"got", "", "Gothic"},
  {"grb", "", "Grebo"},
  {"grc", "", "Greek, Ancient (to 1453)"},
  {"ell", "el", "Greek"},
  {"grn", "gn", "Guarani"},
  {"guj", "gu", "Gujarati"},
  {"gwi", "", "Gwich´in"},
  {"hai", "", "Haida"},
  {"hat", "ht", "Haitian"},
  {"hau", "ha", "Hausa"},
  {"haw", "", "Hawaiian"},
  {"heb", "he", "Hebrew"},
  {"her", "hz", "Herero"},
  {"hil", "", "Hiligaynon"},
  {"him", "", "Himachali"},
  {"hin", "hi", "Hindi"},
  {"hit", "", "Hittite"},
  {"hmn", "", "Hmong"},
  {"hmo", "ho", "Hiri Motu"},
  {"hrv", "hr", "Croatian"},
  {"hun", "hu", "Hungarian"},
  {"hup", "", "Hupa"},
  {"iba", "", "Iban"},
  {"ibo", "ig", "Igbo"},
  {"ice", "is", "Icelandic"},
  {"ido", "io", "Ido"},
  {"iii", "ii", "Sichuan Yi"},
  {"ijo", "", "Ijo"},
  {"iku", "iu", "Inuktitut"},
  {"ile", "ie", "Interlingue"},
  {"ilo", "", "Iloko"},
  {"ina", "ia", "Interlingua (International Auxiliary Language Asso"},
  {"inc", "", "Indic (Other)"},
  {"ind", "id", "Indonesian"},
  {"ine", "", "Indo-European (Other)"},
  {"inh", "", "Ingush"},
  {"ipk", "ik", "Inupiaq"},
  {"ira", "", "Iranian (Other)"},
  {"iro", "", "Iroquoian languages"},
  {"ita", "it", "Italian"},
  {"jav", "jv", "Javanese"},
  {"jpn", "ja", "Japanese"},
  {"jpr", "", "Judeo-Persian"},
  {"jrb", "", "Judeo-Arabic"},
  {"kaa", "", "Kara-Kalpak"},
  {"kab", "", "Kabyle"},
  {"kac", "", "Kachin"},
  {"kal", "kl", "Kalaallisut"},
  {"kam", "", "Kamba"},
  {"kan", "kn", "Kannada"},
  {"kar", "", "Karen"},
  {"kas", "ks", "Kashmiri"},
  {"kau", "kr", "Kanuri"},
  {"kaw", "", "Kawi"},
  {"kaz", "kk", "Kazakh"},
  {"kbd", "", "Kabardian"},
  {"kha", "", "Khasi"},
  {"khi", "", "Khoisan (Other)"},
  {"khm", "km", "Khmer"},
  {"kho", "", "Khotanese"},
  {"kik", "ki", "Kikuyu"},
  {"kin", "rw", "Kinyarwanda"},
  {"kir", "ky", "Kirghiz"},
  {"kmb", "", "Kimbundu"},
  {"kok", "", "Konkani"},
  {"kom", "kv", "Komi"},
  {"kon", "kg", "Kongo"},
  {"kor", "ko", "Korean"},
  {"kos", "", "Kosraean"},
  {"kpe", "", "Kpelle"},
  {"krc", "", "Karachay-Balkar"},
  {"kro", "", "Kru"},
  {"kru", "", "Kurukh"},
  {"kua", "kj", "Kuanyama"},
  {"kum", "", "Kumyk"},
  {"kur", "ku", "Kurdish"},
  {"kut", "", "Kutenai"},
  {"lad", "", "Ladino"},
  {"lah", "", "Lahnda"},
  {"lam", "", "Lamba"},
  {"lao", "lo", "Lao"},
  {"lat", "la", "Latin"},
  {"lav", "lv", "Latvian"},
  {"lez", "", "Lezghian"},
  {"lim", "li", "Limburgan"},
  {"lin", "ln", "Lingala"},
  {"lit", "lt", "Lithuanian"},
  {"lol", "", "Mongo"},
  {"loz", "", "Lozi"},
  {"ltz", "lb", "Luxembourgish"},
  {"lua", "", "Luba-Lulua"},
  {"lub", "lu", "Luba-Katanga"},
  {"lug", "lg", "Ganda"},
  {"lui", "", "Luiseno"},
  {"lun", "", "Lunda"},
  {"luo", "", "Luo (Kenya and Tanzania)"},
  {"lus", "", "lushai"},
  {"mac", "mk", "Macedonian"},
  {"mad", "", "Madurese"},
  {"mag", "", "Magahi"},
  {"mah", "mh", "Marshallese"},
  {"mai", "", "Maithili"},
  {"mak", "", "Makasar"},
  {"mal", "ml", "Malayalam"},
  {"man", "", "Mandingo"},
  {"mao", "mi", "Maori"},
  {"map", "", "Austronesian (Other)"},
  {"mar", "mr", "Marathi"},
  {"mas", "", "Masai"},
  {"may", "ms", "Malay"},
  {"mdf", "", "Moksha"},
  {"mdr", "", "Mandar"},
  {"men", "", "Mende"},
  {"mga", "", "Irish, Middle (900-1200)"},
  {"mic", "", "Mi'kmaq"},
  {"min", "", "Minangkabau"},
  {"mis", "", "Miscellaneous languages"},
  {"mkh", "", "Mon-Khmer (Other)"},
  {"mlg", "mg", "Malagasy"},
  {"mlt", "mt", "Maltese"},
  {"mnc", "", "Manchu"},
  {"mni", "", "Manipuri"},
  {"mno", "", "Manobo languages"},
  {"moh", "", "Mohawk"},
  {"mol", "mo", "Moldavian"},
  {"mon", "mn", "Mongolian"},
  {"mos", "", "Mossi"},
  {"mwl", "", "Mirandese"},
  {"mul", "", "Multiple languages"},
  {"mun", "", "Munda languages"},
  {"mus", "", "Creek"},
  {"mwr", "", "Marwari"},
  {"myn", "", "Mayan languages"},
  {"myv", "", "Erzya"},
  {"nah", "", "Nahuatl"},
  {"nai", "", "North American Indian"},
  {"nap", "", "Neapolitan"},
  {"nau", "na", "Nauru"},
  {"nav", "nv", "Navajo"},
  {"nbl", "nr", "Ndebele, South"},
  {"nde", "nd", "Ndebele, North"},
  {"ndo", "ng", "Ndonga"},
  {"nds", "", "Low German"},
  {"nep", "ne", "Nepali"},
  {"new", "", "Nepal Bhasa"},
  {"nia", "", "Nias"},
  {"nic", "", "Niger-Kordofanian (Other)"},
  {"niu", "", "Niuean"},
  {"nno", "nn", "Norwegian Nynorsk"},
  {"nob", "nb", "Norwegian Bokmal"},
  {"nog", "", "Nogai"},
  {"non", "", "Norse, Old"},
  {"nor", "no", "Norwegian"},
  {"nso", "", "Northern Sotho"},
  {"nub", "", "Nubian languages"},
  {"nwc", "", "Classical Newari"},
  {"nya", "ny", "Chichewa"},
  {"nym", "", "Nyamwezi"},
  {"nyn", "", "Nyankole"},
  {"nyo", "", "Nyoro"},
  {"nzi", "", "Nzima"},
  {"oci", "oc", "Occitan"},
  {"oji", "oj", "Ojibwa"},
  {"ori", "or", "Oriya"},
  {"orm", "om", "Oromo"},
  {"osa", "", "Osage"},
  {"oss", "os", "Ossetian"},
  {"ota", "", "Turkish, Ottoman (1500-1928)"},
  {"oto", "", "Otomian languages"},
  {"paa", "", "Papuan (Other)"},
  {"pag", "", "Pangasinan"},
  {"pal", "", "Pahlavi"},
  {"pam", "", "Pampanga"},
  {"pan", "pa", "Panjabi"},
  {"pap", "", "Papiamento"},
  {"pau", "", "Palauan"},
  {"peo", "", "Persian, Old (ca.600-400 B.C.)"},
  {"per", "fa", "Persian"},
  {"phi", "", "Philippine (Other)"},
  {"phn", "", "Phoenician"},
  {"pli", "pi", "Pali"},
  {"pol", "pl", "Polish"},
  {"pon", "", "Pohnpeian"},
  {"por", "pt", "Portuguese"},
  {"pra", "", "Prakrit languages"},
  {"pro", "", "Provençal, Old (to 1500)"},
  {"pus", "ps", "Pushto"},
  {"que", "qu", "Quechua"},
  {"raj", "", "Rajasthani"},
  {"rap", "", "Rapanui"},
  {"rar", "", "Rarotongan"},
  {"roa", "", "Romance (Other)"},
  {"roh", "rm", "Raeto-Romance"},
  {"rom", "", "Romany"},
  {"run", "rn", "Rundi"},
  {"rup", "", "Aromanian"},
  {"rus", "ru", "Russian"},
  {"sad", "", "Sandawe"},
  {"sag", "sg", "Sango"},
  {"sah", "", "Yakut"},
  {"sai", "", "South American Indian (Other)"},
  {"sal", "", "Salishan languages"},
  {"sam", "", "Samaritan Aramaic"},
  {"san", "sa", "Sanskrit"},
  {"sas", "", "Sasak"},
  {"sat", "", "Santali"},
  {"scc", "sr", "Serbian"},
  {"scn", "", "Sicilian"},
  {"sco", "", "Scots"},
  {"sel", "", "Selkup"},
  {"sem", "", "Semitic (Other)"},
  {"sga", "", "Irish, Old (to 900)"},
  {"sgn", "", "Sign Languages"},
  {"shn", "", "Shan"},
  {"sid", "", "Sidamo"},
  {"sin", "si", "Sinhalese"},
  {"sio", "", "Siouan languages"},
  {"sit", "", "Sino-Tibetan (Other)"},
  {"sla", "", "Slavic (Other)"},
  {"slo", "sk", "Slovak"},
  {"slv", "sl", "Slovenian"},
  {"sma", "", "Southern Sami"},
  {"sme", "se", "Northern Sami"},
  {"smi", "", "Sami languages (Other)"},
  {"smj", "", "Lule Sami"},
  {"smn", "", "Inari Sami"},
  {"smo", "sm", "Samoan"},
  {"sms", "", "Skolt Sami"},
  {"sna", "sn", "Shona"},
  {"snd", "sd", "Sindhi"},
  {"snk", "", "Soninke"},
  {"sog", "", "Sogdian"},
  {"som", "so", "Somali"},
  {"son", "", "Songhai"},
  {"sot", "st", "Sotho, Southern"},
  {"spa", "es", "Spanish"},
  {"srd", "sc", "Sardinian"},
  {"srr", "", "Serer"},
  {"ssa", "", "Nilo-Saharan (Other)"},
  {"ssw", "ss", "Swati"},
  {"suk", "", "Sukuma"},
  {"sun", "su", "Sundanese"},
  {"sus", "", "Susu"},
  {"sux", "", "Sumerian"},
  {"swa", "sw", "Swahili"},
  {"swe", "sv", "Swedish"},
  {"syr", "", "Syriac"},
  {"tah", "ty", "Tahitian"},
  {"tai", "", "Tai (Other)"},
  {"tam", "ta", "Tamil"},
  {"tat", "tt", "Tatar"},
  {"tel", "te", "Telugu"},
  {"tem", "", "Timne"},
  {"ter", "", "Tereno"},
  {"tet", "", "Tetum"},
  {"tgk", "tg", "Tajik"},
  {"tgl", "tl", "Tagalog"},
  {"tha", "th", "Thai"},
  {"tib", "bo", "Tibetan"},
  {"tig", "", "Tigre"},
  {"tir", "ti", "Tigrinya"},
  {"tiv", "", "Tiv"},
  {"tkl", "", "Tokelau"},
  {"tlh", "", "Klingon"},
  {"tli", "", "Tlingit"},
  {"tmh", "", "Tamashek"},
  {"tog", "", "Tonga (Nyasa)"},
  {"ton", "to", "Tonga (Tonga Islands)"},
  {"tpi", "", "Tok Pisin"},
  {"tsi", "", "Tsimshian"},
  {"tsn", "tn", "Tswana"},
  {"tso", "ts", "Tsonga"},
  {"tuk", "tk", "Turkmen"},
  {"tum", "", "Tumbuka"},
  {"tup", "", "Tupi languages"},
  {"tur", "tr", "Turkish"},
  {"tut", "", "Altaic (Other)"},
  {"tvl", "", "Tuvalu"},
  {"twi", "tw", "Twi"},
  {"tyv", "", "Tuvinian"},
  {"udm", "", "Udmurt"},
  {"uga", "", "Ugaritic"},
  {"uig", "ug", "Uighur"},
  {"ukr", "uk", "Ukrainian"},
  {"umb", "", "Umbundu"},
  {"und", "", "Undetermined"},
  {"urd", "ur", "Urdu"},
  {"uzb", "uz", "Uzbek"},
  {"vai", "", "Vai"},
  {"ven", "ve", "Venda"},
  {"vie", "vi", "Vietnamese"},
  {"vol", "vo", "Volapük"},
  {"vot", "", "Votic"},
  {"wak", "", "Wakashan languages"},
  {"wal", "", "Walamo"},
  {"war", "", "Waray"},
  {"was", "", "Washo"},
  {"wel", "cy", "Welsh"},
  {"wen", "", "Sorbian languages"},
  {"wln", "wa", "Walloon"},
  {"wol", "wo", "Wolof"},
  {"xal", "", "Kalmyk"},
  {"xho", "xh", "Xhosa"},
  {"yao", "", "Yao"},
  {"yap", "", "Yapese"},
  {"yid", "yi", "Yiddish"},
  {"yor", "yo", "Yoruba"},
  {"ypk", "", "Yupik languages"},
  {"zap", "", "Zapotec"},
  {"zen", "", "Zenaga"},
  {"zha", "za", "Zhuang"},
  {"znd", "", "Zande"},
  {"zul", "zu", "Zulu"},
  {"zun", "", "Zuni"},
  {"rum", "ro", "Romanian"},
  {"pob", "pb", "Brazilian"},
};


// Find ISO 639-2 (2 or 3 char code) 
const isolang_t *
isolang_find(const char *code)
{
  int i;
  char buf[3];
  if(strlen(code) == 3) {

    // lowercase input code
    buf[0] = code[0] | 0x20;
    buf[1] = code[1] | 0x20;
    buf[2] = code[2] | 0x20;

    for(i = 0; i < sizeof(langtable) / sizeof(langtable[0]); i++)
      if(!memcmp(buf, langtable[i].iso639_2, 3))
        return &langtable[i];


  } else if(strlen(code) == 2) {
    buf[0] = code[0] | 0x20;
    buf[1] = code[1] | 0x20;

    for(i = 0; i < sizeof(langtable) / sizeof(langtable[0]); i++)
      if(!memcmp(buf, langtable[i].iso639_1, 2))
        return &langtable[i];

  }
  return NULL;
}
