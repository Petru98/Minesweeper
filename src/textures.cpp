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
            2847,
            "\x89PNG\15\12\32\12\0\0\0\15IHDR\0\0\0\x90\0\0\0q\10\6\0\0\0:^*\x9F\0\0\0\tpHYs\0\0\13\23\0\0\13\23\1\0\x9A\x9C\30\0\0\12\xD1I"
            "DATx\xDA\xED]\xFDn\xDB""8\14\xA7\24\xB7\xE9\xEE\16\7\xDC\23\xD5I\x80\xBDT\16h\7\xAC/\xB5!\xA9\x83\xBD\xD4\xD6\xAE\xE1\xFD\21+"
            "\xA7\xAA\xFA\xA0>\xAD""8\42\20\xAC\xB1""ES\22\x7F\xFA\x89\xA4\xED\x8C=>>\42""4i\22(\35\0@\xDF\xF7\xC1\27\30\x86\xA1\xE9_\xB1>o"
            "k\xA8I4\3\xE5\x94\xBE\xBF\37\x91~\xA0\xB5\37\xEC\xAB""a\xE8\7\xE3\xB9{\xC2J:\14\3\xA1\xCF\x83\xB4""B\xFB\17\xDF\xCD}\xEB\x89"
            "c\34\x82\xCE\xB9lP\x99""d\xB0\xD8\30\34\xF6U\33\xBC\4x\xC8\xED\x87>I\33\x9B\xDC\xF7}\xB5\xAB\xB9'\x80;\xA7\14\4\xFBj\x9B\xAE"
            "\26\xF0\xB8\x98\x86\2\34\33\xBBP\x81""Ce\x9B\xDC`\30\2\x80n\3\x80o\x9C\xA3\xB6""7]\xBB\xAB\t<\xB6\xED\xA9\xC9\25\xC5@\42\xDE"
            "\x89""e!\35\xF3PAfb\x9C\x83u\x95\16\xD6\xEF\xE2\30\x85\x99L\14""Be&S\xBB\20""f\x92\xD9\xC4\xC5R\xE2\xBC\xA9]\xD1\30(\26""8\xA1"
            "\xE0\xA9Y\x86\xC8\30l\xEA""8\xA9x\26\26\xCB""8\xA1\xC0Q\x99""F0\xD2}\xDF\33Y\xC8\xC4,\xD4\xB8\xC8\xE6\\_\xE0\xA8\xED""C\x81""C"
            "e\37\xF5\xBC)\6R\xEB""F]\xCD\xE0i1\xD1\x95\xC6@\xBA\xD8\xC7\xB7\36""d\xCB\xBCL\xC0\x9A:E\37\22\xDAO\xB1U\xF9\xB0OHJ_u\14\x94K"
            "\16\23\xC7\20\xB1\xDB\xDC\x90q\x91PR}\xB5M\xD6,\xACt\32\x9F\13\34\xD4zP\12\xD6H\t\x90!\xA0?\xBE\xF5\xA2v/\xACI\x94""4\0""5\x89"
            "\22\x86\x88\xC1\xCF\3\35\16\7\xB8\xBF\17/\26\36\16\x87 \x9AM)\xAF\xAF\xAFQ\xFA_\xBF~\15\xD6\xDD\xEF\xF7\xB0\xDF\xEF\xA3\xEC?=="
            "\xB1\x8B\xCC\xC2\x84\xF3""C\1$\x83'\xF6y\x96\x87\xC7\xC7`\xFD\x7F\xB7[X\xAF\xD7\xC5'^\6O\x8C\xFD\xA7\xA7\xA7:\xD2\xF8\xC3\xE1"
            "\xE0\xED""8\25\20""9\2<\xB9\xBC\36""D\xB1\0\20\xF3\xC8\xE5""f\xB3\x81\xDDnG\2\x84/\x80\xE6 Y\13\x89\xA2.s\xA8\xAC\xFC\xAE\x93"
            "\xF5""fsr,\1,\x94\xB6\x9B\xB1\x8D\20\12\10[\20-\1'\xB4\xA8\xF7\xF9\xF3\xE7""3\xF3\xACV+\xE0\x9C""C\xDF\xF7\xE7mn\xB5ZY\xF5\x97"
            "\xB7\xB7g\xE6\xE1\x8C\1\xE7\34\xD8\xF8\35\xC6""cZF\30\35,\xC0\xB1\xD9l\xCE \x90\xFF\xF6\1\xCFn\xB7;\3G\5\24\x95\xFD\xE4\xCFU\0"
            "(\xB6\32\xFC\xED\xDB\xB7""3H\20\21\x8E\xC7#p\xCE\xCF@z~~\xB6\xEA\xFFzy9\x83""D\xD5g\0p\xB4\xE4\14*\x88""bX*VR\x81\xF0\xE2\0\24"
            "\xBB]\xF5}\17\x88x\xFE\xC8@\xE8\xBA\xCE\31p\xB3\xB1\xBDI\xDF\x95\xB2\x88\xF3""8\xEA\x81\xF4]>o\23\xD9\xE9s\x97,1\x90\0Q\10\33"
            "1\xC6\xDE""9N|\xE7\x9C\xC3\xEF\xDF\xBF\xE1v\xDC\xA2\xA2\xF4_^h\x81\xB7`2\17\xF0\xD8\x98\xC4G.\5\x80Y\x83\xE8\xC3x\xEB\x7F 2\17"
            "\0\0\xE7\34\20\21\30""cg\xE7""3\xC6\xE0x<\xC2""b\xB1\x80\x97\x97\27\xE8\xFB\36""8\xE7\xEF""2\31""9\xC6q\xE9\xB3\xD1\xCE\xDB"
            "\xF1h\14z\5\x88t\xE0\xA1\x82\42\24<\xB9\xAEsq\0\12I\xEB\5""8\xC4\26$3\xC8\xDB\xDB\x9B\xB1\4pv\xF4\30\xF3\xD8\xF4\21\0@\2\x8F"
            "\xEC\34J\x9CQ\xD2\x91""5\x83'+\x80\xE4X\xC5\xB7\x96#\x9C\xCF""9?\7\xC1>\5\xF3X}u\xDB\22L\xE4\xBB\x85]C\34\xC4s\0G\27\xE8\x9A"
            "\x8E\xEB\x98\10\21\xA1\xEB\xBA\xF3\xB6s<\36\xCFl\xE2\2\xA2\10~M\xFAHp\xBA\xBAm\xC9\x81\xB5\17(R\xA4\xDF\xB5\7\xE4\xD5\xDDL]"
            "\xADV0\14\xC3""9\xE0\25\xDB\16\0\xC0\xF3\xF3\xB3\23\x84|\4\x89N\xFF\x88\xE8""d\21\x91\xAA""3Cv\xB6.\x9CJ\xD7\\\3\xCA\xB2\x85"
            "\xC5\xDE\34\25u\36""9&\x92\xAF\xE9\xBA\xBE\xA8\xF3 \0\xC0\30""0\xA3""fkr\xD5yv\x92\3\5\3\xEC\xC7""6\xEB\xCD\x86T\13\xBA\x86-"
            "\xAC\3\x88\xBF+\x9E\xF3\xAE:\xE7<^_\t\x98]\xE0\xB1\xC9~\xB7\xFB\0\xA2\24w\xD5/\25\x84]\xCD\xE0\21\xCE\x89\x91""7\2xl\xC0\xD1"
            "9Pn\x9B\23<\x97 \xAC\xC4\xEF\3\xF5}\17\xDF\xBF\x7F\xCF>\x98\xF5z\15?~\xFC\x80\22\xE3)\xF1\34SI;}\xDF\7=W\xD4\1\0<<<d\xEB\\\xC9"
            "\x87\xC6\xF6\xFB=\xDC\xDC\xDC\24\33\xCF\xDC\xECTU\7""2u.\xE7\xC3[\xB9\xB7\x92R\x8B\xE1\x92\xECt\xEA\5k\xCA\xC8RLP\x89\xF1\xCC"
            "\xCD\x8EW\x92\2M\x9A\xA4""b J\xB0U\33\xCB\xC4\6\x8F%\xC6""37;\xDE\0\22\35\xD3\xDDNb\xAC\xCF\xD2Q]\xF5""5UM\xA4\xD4x\xE6""f'\10"
            "@\xA7\7\xBC\xCC\xE7\xC5""9\xC6\xD2\xA4\x9C\2""8\xFA\xC9\x88\xBF""3]j<s\xB3\23\24\3\xB9:\xA7v\xB4\x8F|\x9Cu\xB3\xD9\0\42\30m"
            "\x8As\xA1\xF7\x86J\x8Dgnv\x82\0\xE4\xD3\xB9\24\x9D\24\xE0\xA1\xDA\xF1\5\x91<\x9E/_N\17\33~\xF9\xF2\xBE\x8Dz<d<\xA5\xE6M\xB6#"
            "\xDE\23P\xDF\27P\x8F\xE7\0\21""9\13""cL\xDF""A\x96\xE0\xBDH\37\xF0\xC4\x80H\x88x\17Q}\37\xD1t<T\xC4\xFC\xD8>)\4\xF1t-u\16M\xC7"
            "\xB3\3(d\25\xA5\xA4\xCA\xD4`U\xC7\xE3\3 \x9F\xF1\xE8XA\27\x8F\xE8X\42\xD4\x8E\xB8\x86\0\x8Bzm\xF5xj\26\xE2>\xC0\xD0!<\26\xDD!"
            "\xEC\23\xCB""B\17\17']\xF5\16\x81\xE9x\xC8\2\xF0\xD9\x8E""c\x99H\xD8\xD2\xF9\xC7\4\xDC\xE2\0*)\xB9\xC0ZBd\xF0\xC8L\xA6""c7\xF1"
            "w\12\20M%\35\\\xB9\xA8\xF4\x9E\2\xFC""2\xA3\xE9XN\xC7p\x97\12\42\xEE;\xC9!\xE7k\25""9\xDB\x92\xBF_\xF2""b\xC8\21\xA4{\3h\30"
            "\x86\17+\xD3\xD4\31u\xBFg,\xAE\xEA\x99\3\xAC\xEAx\xE4-D\x8E\23t\xD9\x97\xCFxtvl\xF3\x96\xDA\x8E\xD8\xE6\xE5O\x8C\x9D\xE4""A"
            "\xB4\16\xE1\xB1\xB4\xBF\xDB\xED\xA2\xC0\32S\x95~||_+I\x95\xBE\x97\x98""7j\xD0\x9E{k\xE4>(\xD7!<\7\xBAsL\xBAn<\42\26\21\xC7\xD5"
            "\xD8$d<\xA5\xE6M\xB6\xE3\x9A\27\xB9\xB4\x90\xFAv\6\17\xA1~\xD3*\10\xED\x9C\xCA""B\xD4I\xF7""e\37\x97sS\x8D\xA7\xD4\xBC\x95\xB2"
            "\23\xB5\x85\x89N\xDA\xB6\x95\24\x9D\xD3\x81\xC8""6\31\xA1[W\xA9\xF1\xCC\xCDNT\32/\x8C\x8BG\3t\xE7R\xC8\tD\xB6\xBB\xF1\xFF\xB7"
            "\x8B\x9D\xF4\22\xE3\x99\x9B\x9D\xE8:P\x89\x87\xC7\4""8\4\x90t\xE7RO|n\x99\x9B\35-\x80j\xF8\xC9\xDD\x94`i\17\xC0\x97\21^s\xE7"
            "\x9AS\xEB\6\17\0@W\xEA\xE5\xB5\xF5z]\xE4-\xCE""9\xBE\xF4W\xF3\xE2\x8E\xFD\31\xE5&\xD7-\xEC\x9C\xC6#\xE1\xA3\x93\xAD\xE3_UB\xEC"
            "\xCC\xADo5\xEB\4\xCD\33\x8A\xDF""e\xB2|\xE4v\0\x80[\xCD\xDF[\xCD""9\x9DN\x88\35\37\35\14\xE8\33u\16\xB6\x91:1\xE3\xC9\xAD""C"
            "\xF5\xE9V\xC1\xDF\x87\13\x9A\14\xA1\2`\x9B""A\x97N\x88\35\xAA\16:@\xE4\xD2\xA1\0!T'v<9u(>\xDDj\10\xEC\xC3\x85\xC1""0Q.\xA7\xD4"
            "\xA2\23""2\36\x97\x8E\15\x84>:\xB5\x8C'd\xAE\xB7.\6\xF2""1f34\xB5N\x8E\t\xB7""1\x90\x8FN-\xE3\t\x99\xEB\xC6@\x8D\x81\32\3""5\6"
            "j\14\xD4\30h\xAE\14\4\x84\x95\xE1\x83\xD6\xA9tB\xC6""C\xD1\xD9\22\xFA\32\xCB@%\xC7\x93\x94\x81""Bk:5\xD7\x81r\xE8\xA4\xAA\3"
            "\xE5\xA8Q\xA5\xAA\3y\x8C\xE7}\xC1rK\30\x98\x8B\xD6|(\xDA\xD6\xC9""9\xEB\xCCh\xDE\xCA""2P\xA9\xCAm\xCDLW\x8A\x81\xB6%\31\xA8T"
            "\14T*f\xA8""9\xD6\xAA\xD9N\xF5YX\xA9\xAC\xA5\xE6l\xAF""f;\xD5\xD7\x81J\xD5Mj\xAE""7\xD5l\xA7""1Pc\xA0\xC6@\x8D\x81\32\3""5\6"
            "\xBAV\6\xCA\xFD<P\xA9\xE7gJ=\xABT\xD3\xBC\xA5~\xF6\xCA\xFBy\xA0\x9A\xEA\31\xA9\xEA@\xB9\xAB\xE4s\xAD\3y?\x91""8\xC7\x8Aj\xEB["
            "\x91\xBE\xB5\xB7""2\x9A\xC4\xBD\x95Q\xD5o\x8B-;@\xCE\1^_\1~#\xB0\xE6\x9F\xCB\22\xCA\33\37\xD9\xA4S\xFEG\xEEO\xB7\xD5""1\xA3n^p"
            "n~\x88\xE9\xF4\xA4\xD2\xB1\xEA'\xAB\4\x80..\x9C\xE0""c\xA7\31qE\x98\x8E\x99&7\xD9*\xEA\30`\xC7\0\xFF\xF9\xFB\xFD\xF5\26\14\xF0"
            "\xAF?\0;\xFE\xFF\xF1\5\3\\\xDEX\xFB{b\xB9%\xE0\xC2\17\xB8\xB6\x98\xD1""4O\xAE\xBF\xE5""c\xD5\xFB!\26\xF5H\x9C\x98\xA0\x95\xDA"
            "1\xC0\33\16\xB8\xEC\xDE\xB7\xBFQ\x9C|7\x9EW\x9D/@\xF3\xF7_Vg\x9Dt\xA5\xE3\x7F~\42\xF5\17\3\xC6\xEB\13\xA0*\xFC\20\3 \27\xCA}:"
            "\36\xB5\x97\xCB[Zg\xD0\xFF""c\xA9\xB0\21h\x81""e\xEC\xCB\42\xCCi:\7\xA1""c\x9E\xD0\xE1\xD8j\xFD@\xD9\xC2T\x8A""f\32Ze\16z5\xD1"
            "}\xA8.\xDC\xDD\xB9\xDB\xFC\xFA""E\xCE)\xB5}y\3`w7\xC9&5j\xBC\xB5\xFA\x81\2\xA0\22\xB5 \xF4""a\34\0\x80\x9F?%fY\xBCo{;\xC6;\xCB"
            "\xA5""bd\xBC""B\xD7\xB9\xFB\42\xD8\xE7\xE7+\xB0\x80\0\xDE""5g\xA8\xB4""c\x86\xEF>\xD7\xAC>H\xC7\x84\xD4\31\24\xBC\x89@\xF9\x86"
            "\x7F\xD4\xE9\0\xB0\3\xC0\xE5""B\x89\x8F\26\xA7@\xF8\xEE\xF6}\20M\t$;\xEE\25""D\xA3#+Cb\xA6\x86\xB5\xFB\xA1I\x93&M.Ct\xFBnL\xA0"
            "\x85\0\x93\xDC\x82\x98\xCA\xAEO\xDFr\xF7\21\15\xFE-2\xC0""b\x81\xD6\x84\xC1!V\xDC\xB7\24\xFD\xC3)\xC6\xC4\xA1I\x93\10\xE9<\x91"
            "\xCD,\x88g\32\xBA""FE\xCFt\xDC""d\7\3\xA8\xD8""e\x83\21\xED\xA1""a\xABg\1sC\xB1Mm\23\xBB\xC5#!t\xA1\xF8\xE2|M\14HA]\xC7M\xF7"
            "\x84l\xC7)v( \xA7\xD8\x88\xB9\xF5\x80\x91s\3\x9E\xB6}\xB6h\x8A\37S\xF4\37U\6""b\x96\x80""4toe\x9E\xC7S\xEE\xE1\xCC\23t\xA5\xE3"
            "\x8E\\1\33#$KI\xE7\xA6K\xE4\x8CRN\xAF\xCD\36\13\4\17""e\x81N\x99U\x92m\xF3""B+\xAE\xE6\x8C""bj6*\x95\xA1""1\10\xBB]\x82\24\6"
            "2\5l\xCCp.\xF5}\33\x96""8h\xB4\xD9`\x89\xEC\x85\xCE\15\xB3\xD4lb\xFB\xE7[\xD3\xA3\xF4\x9F""9\xFAz\x91\x8C\xD1\xA4\22\x9Fu\x89"
            "\x8C\xB7\7\xE0\xAFT|\xB2-*\35\x86""fY\xBE\x99\37#P2F\\?f~\xB0\xC0\xFC\xC7\xFA+\x89\xF0""Di%F\xE8\x86R\xEA$\xA5\xFB\t\xAF\x8F"
            "\x99\xE7""3\xD9\26\xC6""2\x80\xC3\xF7\xFA,\xC0^hP\xCC\42\xFB\17\x89\xFA\x9F\x8Ai\x8A\xC6\xA3]\xA1\x95\xD9""b\xA4\x99\xC7@HD4K"
            "\xB8\xFA\xA9\x81""8\xA5\xD0\x86\21\xE3\xCD\31\x93\xF9\xCCS\16\xA6\xC9\xBEp\xA7\xB8\33\x8F\27\x92\xC5\xD5\34\x93U#\xDD\xC4\16\t"
            "\x89'\xE4\x9B{,\x90\31K\xC6(\xBE\xEC""C\31oL\xB6{\x91\0ju\xA3+b \x8C\0\x86|,d\x95\xB3""B\xAB\10\13\xEB\xFA\xC4\x88\xA5\x9E`L"
            "\32\3\xC5\xA6\xA6S&\0%\xAE\x9F{~r\\\xBF\x88\xBF\xFE\3Ur\x86\5\x98],\x98\0\0\0\0IEND\xAE""B`\x82"
        };
    }
}
