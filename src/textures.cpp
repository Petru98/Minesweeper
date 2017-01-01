#include "textures.hpp"

namespace Resources
{
    namespace Textures
    {
        namespace Rectangles
        {
            const sf::IntRect cell[] =
            {
                {0*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {1*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {2*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {3*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {4*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {5*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {6*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {7*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {8*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},

                {0*CELL_WIDTH, CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT},
                {1*CELL_WIDTH, CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT},
                {2*CELL_WIDTH, CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT},
                {3*CELL_WIDTH, CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT},
                {4*CELL_WIDTH, CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT},
                {5*CELL_WIDTH, CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT},
                {6*CELL_WIDTH, CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT},
            };

            const sf::IntRect smiley[] =
            {
                {0*SMILEY_WIDTH, 2*CELL_HEIGHT, SMILEY_WIDTH, SMILEY_HEIGHT},
                {1*SMILEY_WIDTH, 2*CELL_HEIGHT, SMILEY_WIDTH, SMILEY_HEIGHT},
                {2*SMILEY_WIDTH, 2*CELL_HEIGHT, SMILEY_WIDTH, SMILEY_HEIGHT},
                {3*SMILEY_WIDTH, 2*CELL_HEIGHT, SMILEY_WIDTH, SMILEY_HEIGHT},
                {4*SMILEY_WIDTH, 2*CELL_HEIGHT, SMILEY_WIDTH, SMILEY_HEIGHT}
            };

            const sf::IntRect counter_digit[] =
            {
                {0 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {1 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {2 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {3 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {4 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {5 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {6 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {7 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {8 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {9 *COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT},
                {10*COUNTER_DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT, COUNTER_DIGIT_WIDTH, COUNTER_DIGIT_HEIGHT}
            };

            const sf::IntRect text[] =
            {
                {0        , 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT              , 26, TEXT_HEIGHT},
                {26+8     , 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT              , 32, TEXT_HEIGHT},
                {26+8+32+8, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT              , 50, TEXT_HEIGHT},
                {0        , 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + TEXT_HEIGHT, 41, TEXT_HEIGHT},
                {41+8     , 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + TEXT_HEIGHT, 57, TEXT_HEIGHT},
                {41+8+57+8, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + TEXT_HEIGHT, 29, TEXT_HEIGHT}
            };

            const sf::IntRect digit[] =
            {
                {0 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {1 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {2 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {3 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {4 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {5 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {6 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {7 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {8 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {9 *DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT},
                {10*DIGIT_WIDTH, 2*CELL_HEIGHT + SMILEY_HEIGHT + COUNTER_DIGIT_HEIGHT + 2*TEXT_HEIGHT, DIGIT_WIDTH, DIGIT_HEIGHT}
            };
        }

        const Resource pack =
        {
            2990,
            "\x89PNG\15\12\32\12\0\0\0\15IHDR\0\0\0\x90\0\0\0q\10\6\0\0\0:^*\x9F\0\0\0\tpHYs\0\0\13\23\0\0\13\23\1\0\x9A\x9C\30\0\0\13`IDAT"
            "x\xDA\xED]\xEBn\32;\20\36\x9BM\xC8\xB9\xE8H\xE7\x89\xB2\x80\xD4\x97\xE2H\xA1R\xF3R\xAD \x8B\xFARm\xD2""0\xE7\7kj\34_\xC6W\xCC"
            "\xE2\x91P\xC0\xEB\xF1\xF8\xF2\xF9\xF3x\xD6\xBB""a\x9B\xCD\6\xA1I\x93@\xE9\0\0\xFA\xBE\17.`\30\x86\xA6\x7F\xC3\xFA\xBC\xCD\xA1&"
            "\xD1\14\x94S\xFA\xFEqD\xFA\x9E\x96\x7F\xB0\xCF\x86\xA1\37\x8C\xD7\36\t3i?\14\x84:\17\xD2\14\xED?\xFC""6\xD7\xAD'\xB6q\10\xBA"
            "\xE6\xB2""Ae\x92\xC1""bcp\xD8Wm\xF0\22\xE0!\xE7\37\xFA$yl\xF2\xD8\xF7\xD5\xCE\xE6\x9E\0\xEE\x9C""2\20\xEC\xABy\xBAZ\xC0\xE3""b"
            "\32\12pl\xEC""B\5\16\x95mr\x83""a\10\0\xBA\15\0\xBE~\x8E\x9A\xDFTvW\23xl\xCBS\x93\33\xF2\x81\x84\xBF\23\xCB""B:\xE6\xA1\x82"
            "\xCC\xC4""8{\xEB,\35\xAC\xBF""E\32\x85\x99L\14""Be&S\xBE\20""f\x92\xD9\xC4\xC5R\xE2\xBA)_Q\37(\26""8\xA1\xE0\xA9Y\x86H\37\xEC"
            "\xD2~R\xF1]X,\xE3\x84\2Ge\32\xC1H\x8F}od!\23\xB3P\xFD\42\xDB\xE0\xFA\2G\xCD\37\12\34*\xFB\xA8\xD7M>\x90\32""7\xEAj\6O\xF3\x89n"
            "\xD4\7\xD2\xF9>\xBE\xF1 \xDB\xCE\xCB\4\xACKo\xD1\x87\x84\xF6S,U>\xEC\23\xB2\xA5\xAF\xDA\7\xCA%\xFB\13\xFB\20\xB1\xCB\xDC\x90q"
            "\x92P\xB6\xFAj\x9E\xAC\xBB\xB0\xD2\xDB\xF8\\\xE0\xA0\xC6\x83R\xB0""FJ\x80\14\1\xF5\xF1\x8D\27\xB5{aM\xA2\xA4\1\xA8I\x94""0D\14"
            ">\17\xB4\xDF\xEF\xE1\xF1""1<X\xB8\xDF\xEF\x83h6\xA5\xBC\xBD\xBD""E\xE9\x7F\xF9\xF2%Xw\xB7\xDB\xC1n\xB7\x8B\xB2\xFF\xFC\xFC\xCC"
            "\xAEr\27&\6?\24@2xb\xCF\xB3<m6\xC1\xFA\xFF\xAD\xD7\xB0\\.\x8Bw\xBC\14\x9E\30\xFB\xCF\xCF\xCFul\xE3\xF7\xFB\xBD\xF7\xC0\xA9\x80"
            "\xC8\xE1\xE0\xC9\xE1\xF5 \x8A\5\x80\x98#\x97\xAB\xD5\12\xB6\xDB-\t\20\xBE\0\x9A\x82""d\15$\x8A\xB8\xCC\xBE\xB2\xF0\xBBN\x96"
            "\xAB\xD5q`\t`\xA1\xE4]\x8Dy\x84P@\xD8\x9Ch\t8\xA1""A\xBDO\x9F>\x9D\x98g\xB1X\0\xE7\34\xFA\xBE?-s\x8B\xC5\xC2\xAA?\xBF\xBF?1\17"
            "g\14""8\xE7\xC0\xC6\xDF""0\xA6i\31""a\34`\1\x8E\xD5ju\2\x81\xFC\xDD\7<\xDB\xED\xF6\4\34\25PT\xF6\x93?7\1\xA0\xD8h\xF0\xD7\xAF_"
            "O AD8\34\16\xC0""9?\1\xE9\xE5\xE5\xC5\xAA\xFF\xF3\xF5\xF5\4\22U\x9F\1\xC0\xC1\xB2gPA\24\xC3R\xB1\x92\12\x84W\7\xA0\xD8\xE5\xAA"
            "\xEF{@\xC4\xD3G\6""B\xD7uN\x87\x9B\x8D\xF9M\xFA\xAE-\x8B\xB8\x8E\xA3\36H\xBF\xE5\xEB""6\x91\7}\xEA\x92\xC5\7\22 \12""a#\xC6"
            "\xD8\xD9\xC0\x89\xDF\x9Cs\xF8\xF5\xEB\27\xDC\x8FKT\x94\xFE\xEB+\xCD\xF1\26L\xE6\1\36\33\x93\xF8\xC8\xB5\0""0\xAB\23\xBD\37o"
            "\xFD\17""D\xE6\1\0\xE0\x9C\3\42\2""c\xEC""4\xF8\x8C""18\34\16""0\x9B\xCD\xE0\xF5\xF5\25\xFA\xBE\7\xCE\xF9\xD9NF\xF6q\\\xFAl"
            "\xB4\xF3~8\30\x9D^\1\42\35x\xA8\xA0\10\5O\xAEr\xAE\16@!\xDBz\1\16\xB1\4\xC9\14\xF2\xFE\xFEn\14\1\x9C\6z\xF4yl\xFA\10\0 \x81G"
            "\36\34\x8A\x9FQr k\6OV\0\xC9\xBE\x8Ao,G\14>\xE7\xFC\xE4\4\xFB\4\xCC""c\xF5\xD5""eK0\x91\xEF\22v\13~\20\xCF\1\34\x9D\xA3kJ\xD7"
            "1\21\42""B\xD7u\xA7""e\xE7p8\x9C\xD8\xC4\5""D\xE1\xFC\x9A\xF4\x91""0\xE8\xEA\xB2%;\xD6>\xA0H\xB1\xFD\xAE\xDD!\xAF\xEE""f\xEA"
            "b\xB1\x80""a\30N\16\xAFXv\0\0^^^\x9C \xE4#Ht\xFA\7""D'\x8B\x88\xAD:3\xEC\xCE\x96\x85\xB7\xD2""5\xC7\x80\xB2,a\xB1""7GE\x9CG"
            "\xF6\x89\xE4""2]\xE5\x8B""8\17\2\0\x8C\16""3j\x96&W\x9Cg+\15\xA0`\x80\xDD\x98g\xB9Z\x91""bA\xB7\xB0\x84u\0\xF1w\xC5s\xDEU\xE7"
            "\x9C\xC7\xEB+\16\xB3\13<6\xD9m\xB7\37@\x94\xE2\xAE\xFA\xB5\x82\xB0\xAB\31<bpb\xE4\x9D\0\36\33pt\3(\xE7\xCD\t\x9Ek\20V\xE2\xFD@"
            "}\xDF\xC3\xB7o\xDF\xB2""7f\xB9\\\xC2\xF7\xEF\xDF\xA1""D{J\x9C""c*i\xA7\xEF\xFB\xA0sE\35\0\xC0\xD3\xD3S\xB6\xCA\x95<4\xB6\xDB"
            "\xED\xE0\xEE\xEE\xAEX{\xA6""f\xA7\xAA""8\x90\xA9r9\17o\xE5^JJM\x86k\xB2\xD3\xA9\5\xD6\xB4#K\xD1""A%\xDA""35;^\x9B\24h\xD2$\25"
            "\3Q\x9C\xAD\xDAX&\xD6y,\xD1\x9E\xA9\xD9\xF1\6\x90\xA8\x98\xEEv\22""c}\x96\x8A\xEA\xA2\xAF\xA9""b\42\xA5\xDA""35;A\0:\36\xF0""2"
            "_\27\xD7\30K\xB3\xE5\24\xC0\xD1wF\xFC\x9D\xE9R\xED\x99\x9A\x9D \37\xC8U9\xB5\xA2}\xE4q\xD6\xD5j\5\x88`\xB4)\xAE\x85\xDE\33*"
            "\xD5\x9E\xA9\xD9\t\2\x90O\xE5RTR\x80\x87j\xC7\27""Dr{>\x7F>\36""6\xFC\xFC\xF9<\x8F\x9A\36\xD2\x9ER\xFD&\xDB\21\xCF\t\xA8\xCF"
            "\13\xA8\xE9""9@D\xDE\x85""1\xA6\xAF K\xF0\\\xA4\17xb@$D<\x87\xA8>\x8FhJ\17\25\xD1?\xB6O\12""A<\x96\xA5\xF6\xA1)=;\x80""BfQJ"
            "\xAAL\15V\xB5=>\0\xF2i\x8F\x8E\25t\xFE\x88\x8E%B\xED\x88""2\4X\xD4\xB2\xD5\xF4\xD4,\xC4}\x80\xA1""Cx,\xBA""C\xD8'\x96\x85\x9E"
            "\x9E\x8E\xBA\xEA\35\2Sz\xC8\4\xF0Y\x8E""c\x99H\xD8\xD2\x8D\x8F\t\xB8\xC5\1TRr\x81\xB5\x84\xC8\xE0\x91\x99L\xC7n\xE2{\12\20]J:"
            "\xB8qQ\xE9=\5\xF8""eF\xD3\xB1\x9C\x8E\xE1\xAE\25""D\xDC\xB7\x93""C\xAE\xD7*\xF2nK\xFE}\xCD\x93!\x87\x93\xEE\15\xA0""a\30>\xCCL"
            "Se\xD4\xF5\x9E\xB1\xB8\xA8g\16\xB0\xAA\xED\x91\x97\20\xD9O\xD0\xED\xBE|\xDA\xA3\xB3""c\xEB\xB7\xD4v\xC4""2/\x7F""b\xEC$w\xA2u"
            "\10\x8F\xA5\xFD\xEDv\33\5\xD6\x98\xA8\xF4""fs\36+I\xB5}/\xD1oT\xA7=\xF7\xD2\xC8}P\xAE""Cx\16t\xE7\xE8t]{\x84/\42\xD2U\xDF$\xA4"
            "=\xA5\xFAM\xB6\xE3\xEA\27""9\xB4\x90\xFAv\6\17\xA1~\xD3,\10\xAD\x9C\xCA""B\xD4N\xF7""e\37\xD7\xE0\xA6jO\xA9~+e'j\t\23\x95\xB4-"
            "+)*\xA7\3\x91\xAD""3B\x97\xAER\xED\x99\x9A\x9D\xA8m\xBC""0.\x8E\6\xE8\xAE\xA5\x90#\x88lw\xE3\x7F\xE7\x8B\xED\xF4\22\xED\x99"
            "\x9A\x9D\xE8""8P\x89\xC3""c\2\34\2H\xBAk\xA9;>\xB7L\xCD\x8E\26@5\xBCr7%X\xDA\1\xF8""2\xC2k\xAE\\\33\xD4\xBA\xC1\3\0\xD0\x95zxm"
            "\xB9\\\26y\x8As\x8A\17\xFD\xD5<\xB9""c_\xA3\xDC\xE4\xB6\x85\x9D\xB6\xF1H\xF8\xE8""d\xED\xF8\xABJ\x88\x9D\xA9\xD5\xAD""f\x9D"
            "\xA0~C\xF1^&\xCBG\xCE\7\0\xB8\xD6|_k\xAE\xE9tB\xEC\xF8\xE8`@\xDD\xA8}\xB0\x8E\xD4\x89iOn\35\xEA\x98\xAE\25\xFC}(\xD0""d\10\25"
            "\0\xDB\14\xBAtB\xECPu\xD0\1\42\x97\16\5\10\xA1:\xB1\xED\xC9\xA9""C\31\xD3\xB5\x86\xC0>\24\14\x86\x8Er\15J-:!\xEDq\xE9\xD8@\xE8"
            "\xA3SK{B\xFAz\xED""b \37""c6C\x97\xD6\xC9\xD1\xE1""6\6\xF2\xD1\xA9\xA5=!}\xDD\30\xA8""1Pc\xA0\xC6@\x8D\x81\32\3M\x95\x81\x80"
            "03|\xD0z)\x9D\x90\xF6Pt\xD6\x84\xBA\xC6""2P\xC9\xF6$e\xA0\xD0\x98N\xCDq\xA0\34:\xA9\xE2@9bT\xA9\xE2@\36\xED""9\17X\xAE\t\15s"
            "\xD1\x9A\17""E\xDB*9e\x9D\t\xF5[Y\6*\25\xB9\xAD\x99\xE9J1\xD0\xBA$\3\x95\xF2\x81J\xF9\14""5\xFBZ5\xDB\xA9~\27Vj\xD7R\xF3n\xAF"
            "f;\xD5\xC7\x81J\xC5Mj\x8E""7\xD5l\xA7""1Pc\xA0\xC6@\x8D\x81\32\3""5\6\xBAU\6\xCA}\36\xA8\xD4\xF9\x99Rg\x95j\xEA\xB7\xD4g\xAF"
            "\xBC\xCF\3\xD5\24\xCFH\25\7\xCA\35%\x9Fj\34\xC8\xFB""D\xE2\24#\xAA\xADnE\xEA\xD6\x9E\xCAh\22\xF7TFU\xEF\26\x9Bw\x80\x9C\3\xBC"
            "\xBD\1\xFC""B`m|\xAEK(O|d\x93N\xF9\x8F\xDC\x7F\xDC\xD7\xC6\x8C\xA6W\x7F\xE6\xB2s-\xAF\25\xFD\15\x9E\x8BJ\xC7j_JK\0\10\xAF\xCE"
            "\x9D\xE0#x\30\x91\x99Li:\xD6J\xCA""f\35\3\xEC\30\xE0\xBF\xFF\x9C\x97""7c\x80\x7F\xFF\t\xD8\xF1\xDF\xE9""3\6""8\xBF\xB3\xD6\xF7"
            "\xC8rs\xC0\x99\27p]/\x93SAF\xF9.\xA7\xD9\\\12S\xF9r\x9A\xED\5\xC9\xF9\xC0\x89\1yM\xFF\x8A\35\15""e\42\25$w\34p\xDE\x9D\xE7\xBF"
            "S\6\xF9""a\xBC\xAE\16\xBE\0\xCD?\x7F[\xFFU\xFCQWJ\xFF\xEB\17J\xFDt\xAF\xED\xF6y\xC5""7\5@\xBEL\xE5*\xBF\xC4\x92\13\xCE\x99\x8A"
            "\6\xC6q\1(\xCA\xA7\x92\x97\xB4\xCE\xA0\xFF\xE7\\a#\xD0\2\xCBX\x97\x99W\xBDl\3""dz!\x9F\xEB\xAF\xAD|\33\xDB\xF8\0(\xAFO\xA5\xBE"
            "\xE2\x8E)\xCB\31Ji\xBE\xBB\42\26\xA1\13\17\17\xEE<?\x7F\x92\xF7\x94\xDA\xBA\xBC\3\xB0\x87\xBBT\xBEW\xCA""74\xAB""e\xA8\xAF\35"
            "\xBDT\xBD\xF4\0*\21\13""B\37\xC6\1\0\xF8\xF1""Cb\x96\xD9y\xDE\xFB\xD1\xDF\x99\xCF\xF5s\xB8\xEB\xDCu\21\xEC\xF3\xE3\15\x98\xBF"
            "\3\xEFzg\xAC\xFC^T\xD9\xB7""1\xFD[\24J\x99\xF5;\xE9\x98p\t\13r\xA2\x85\xA3|\xC7?\xEAt\0\xD8\1\xE0|\xA6\xF8G\xB3\xA3#\xFCp\x7F"
            "\xEE""DS\34\xFA\x8E\xFB""8\xD1\xAE\xFF\xDE""aZ&|\xFD\20\xD3\x92\23\xB2\x84\x95q\xA2\x9B""4i\xD2\xE4R2\0\x9E}b\xCB\xBA""D\x88oS"
            "o\20R\xD4-w\35\15""7J\13\1\xA8\2\20\xE4\6\xD0\xA5@F\xB5\33[?,x7A\xB6\xC5\xA1I\x93\10q\xBFh\\f\xA4^\x8A\xE7\xA8L\xD5\3\x83\1"
            "\xF0\xC3_Y\xCF\x94n\xB2\xA3\xCBG\x98\xC9l\3L\xCCh\xB6\xF9\xAD+\xAE\xA9""3^M\x93\xF5\xD5\xDFjyj\31&6q\xD9\xA6\xE6\te\14""6\xC6"
            "\xBF\xC4w\x95\xB1\x98\24\37\x93\xAF\xC9z\xEA\xEF\xE3w\x9B\17""d\xFA\xEDJW\xCB\xA2\xA4S\xEC\20\xE8\37""7\x80\xEAo]\36\x97\x9F"
            "\xE2\xFAN)\x83\xE2\3\xF9\xD4\xCF\xC7\7""2-9\xE2\xBB)\17%]\xFE\xDEi\x99\xC0\xC6""4T1\xB1\x86)=\xA1\xEF""E\x99\xB1)|\xA2\xD0""2r"
            "\xF9l\xCC\20\xF1\x97\31\x87\21\xEE\12\xF8\xF8S]0\20RK_\xF6\0Y\xEC\xB2\20Z\x86\xBCL\xD9\x80\x92\xA2~\xC1\xED\xF2\xB8\xF5\xE4"
            "\xE7""D\x97\xDA\xA1\25\xDE\t^\x92\x8DJ\xED\xD0\xC4\xCD""0\xDF\xDD\x9A+\x7Fgu\x94""e\x87W\xBE\xA6\xA6\xA7`\37S\35\22""2\x8E\x98"
            "\xFD:'9\xB4<\xB5\14""5\xDD\xA5\x97\xB2~6\xC7\xD8\x95_\xE4UA\xA6+C\xE4""a\x90j\x9C\x86v0\xFF\xEA""bg\xA9\16\xFA%\1L\xDF\16\xC0"
            "\xDF\xAA\xA8g\x7F\xA8y\15\xA0\xB6\xE6\xC3\x84u1\xD9""A\xE5:F\x94\37\xD3?X\xA0\xFF""c\xC7+\x89p\x8F\6""c\xE0\xB5\24\xE5\xA7\xC8"
            "\37\xC9\xF8\27/\37""3\xF7g\xB2%\x8C""e\0\x87o\xF9,\xC0\36\6\xCE>\26Y\x7FHT\xFFTLS\xD4\37\xED\12\xCD\xCC\xE6#M\xDC\7""B\42\xA2Y"
            "\xC2\xD9\x8F""D\x90""a\6\x9F\xC3\xD7\xC7\xC2""D\x93\4#\x98#\x84i\xB2O\xDCK\xDC\x8DG\17\xF0\\x\xA7[\xADOV\x8Dt\27\36\x90\20\x7F"
            "B>\x97\xCD\2\x99\xB1\xA4\x8F\xE2\xCB>\x94\xF6\xC6\xECv\xAF\22@\xD7\xC0""8M\22\1\10#\x80!\xA7\x85\xCCrVh\26""aa]\37\37\21\13"
            "\xB4!\xB9\17\24\xBB""5\xBD\xE4\6\xA0""D\xF9\xB9\xFB'G\xF9""E\xC6\xEB\x7F?\x91\x9FI}b\xFA\xC8\0\0\0\0IEND\xAE""B`\x82"
        };
    }
}
