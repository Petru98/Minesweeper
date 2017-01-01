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
            2993,
            "\x89PNG\15\12\32\12\0\0\0\15IHDR\0\0\0\x90\0\0\0q\10\6\0\0\0:^*\x9F\0\0\0\tpHYs\0\0\13\23\0\0\13\23\1\0\x9A\x9C\30\0\0\13""cID"
            "ATx\xDA\xED]\xEBn\42\xB9\22.\x9BN\xC8\xEEY\xADt\x9E(\15H\xF3R\34)\x8C""4y\xA9\31""A\32\xCDK\xCD$\23\xEA\xFC\xA0M\x8C\xE3K\xF9"
            "\x8Ai\\\22\12\xB8]._>\x7F.W\xBB;l\xB3\xD9 4i\22(\35\0@\xDF\xF7\xC1\5\14\xC3\xD0\xF4oX\x9F\xB7""9\xD4$\x9A\x81rJ\xDF?\x8EH\xDF"
            "\xD3\xF2\17\xF6\xD9""0\xF4\x83\xF1\xDA#a&\xED\x87\x81P\xE7""A\x9A\xA1\xFD\xA7\xDF\xE6\xBA\xF5\xC4""6\16""A\xD7\\6\xA8L2Xl\14"
            "\16\xFB\xAA\15^\2<\xE4\xFC""C\x9F$\x8FM\36\xFB\xBE\xDA\xD9\xDC\23\xC0\x9DS\6\x82}5OW\13x\\LC\1\x8E\x8D]\xA8\xC0\xA1\xB2Mn0\14"
            "\1@\xB7\1\xC0\xD7\xCFQ\xF3\x9B\xCA\xEEj\2\x8FmyjrC>\x90\xF0wbYH\xC7<T\x90\x99\30go\x9D\xA5\x83\xF5\xB7H\xA3""0\x93\x89""A\xA8"
            "\xCC""d\xCA\27\xC2L2\x9B\xB8XJ\\7\xE5+\xEA\3\xC5\2'\24<5\xCB\20\xE9\x83]\xDAO*\xBE\13\x8B""e\x9CP\xE0\xA8L#\30\xE9\xB1\xEF\x8D"
            ",db\26\xAA_d\33\\_\xE0\xA8\xF9""C\x81""Ce\37\xF5\xBA\xC9\7R\xE3""F]\xCD\xE0i>\xD1\x8D\xFA@:\xDF\xC7""7\36""d\xDBy\x99\x80u\xE9"
            "-\xFA\x90\xD0~\x8A\xA5\xCA\x87}B\xB6\xF4U\xFB@\xB9""d\x7F""a\37\42v\x99\33""2N\22\xCAV_\xCD\x93u\27Vz\33\x9F\13\34\xD4xP\12"
            "\xD6H\t\x90!\xA0>\xBE\xF1\xA2v/\xACI\x94""4\0""5\x89\22\x86\x88\xC1\xE7\x81\xF6\xFB=<>\x86\7\13\xF7\xFB}\20\xCD\xA6\x94\xB7"
            "\xB7\xB7(\xFDo\xDF\xBE\5\xEB\xEEv;\xD8\xEDvQ\xF6\x9F\x9F\x9F\xD9U\xEE\xC2\xC4\xE0\x87\2H\6O\xECy\x96\xA7\xCD&X\xFF\x7F\xEB""5,"
            "\x97\xCB\xE2\35/\x83'\xC6\xFE\xF3\xF3s\35\xDB\xF8\xFD~\xEF=p* r8xrx=\x88""b\1 \xE6\xC8\xE5j\xB5\x82\xEDvK\2\x84/\x80\xA6 Y\3"
            "\x89\42.\xB3\xAF,\xFC\xAE\x93\xE5ju\34X\2X(yWc\36!\24\20""6'Z\2NhP\xEF\xCB\x97/'\xE6Y,\26\xC0""9\x87\xBE\xEFO\xCB\xDC""b\xB1"
            "\xB0\xEA\xCF\xEF\xEFO\xCC\xC3\31\3\xCE""9\xB0\xF1""7\x8CiZF\30\7X\x80""c\xB5Z\x9D@ \x7F\xF7\1\xCFv\xBB=\1G\5\24\x95\xFD\xE4"
            "\xCFM\0(6\32\xFC\xFD\xFB\xF7\23H\20\21\16\x87\3p\xCEO@zyy\xB1\xEA\xFF~}=\x81""D\xD5g\0p\xB0\xEC\31T\20\xC5\xB0T\xAC\xA4\2\xE1"
            "\xD5\1(v\xB9\xEA\xFB\36\20\xF1\xF4\x91\x81\xD0u\x9D\xD3\xE1""fc~\x93\xBEk\xCB\42\xAE\xE3\xA8\7\xD2o\xF9\xBAM\xE4""A\x9F\xBA""d"
            "\xF1\x81\4\x88""B\xD8\x88""1v6p\xE2""7\xE7\34\xFE\xFC\xF9\3\xF7\xE3\22\25\xA5\xFF\xFAJs\xBC\5\x93y\x80\xC7\xC6$>r-\0\xCC\xEA"
            "D\xEF\xC7[\xFF\3\x91y\0\0""8\xE7\x80\x88\xC0\30;\15>c\14\16\x87\3\xCC""f3x}}\x85\xBE\xEF\x81s~\xB6\x93\x91}\34\x97>\33\xED\xBC"
            "\37\16""F\xA7W\x80H\7\36*(B\xC1\x93\xAB\x9C\xAB\3P\xC8\xB6^\x80""C,A2\x83\xBC\xBF\xBF\33""C\0\xA7\x81\36}\36\x9B>\2\0H\xE0\x91"
            "\7\x87\xE2g\x94\34\xC8\x9A\xC1\x93\25@\xB2\xAF\xE2\33\xCB\21\x83\xCF""9?9\xC1>\1\xF3X}u\xD9\22L\xE4\xBB\x84\xDD\x82\37\xC4s\0G"
            "\xE7\xE8\x9A\xD2uL\x84\x88\xD0u\xDDi\xD9""9\34\16'6q\1Q8\xBF&}$\14\xBA\xBAl\xC9\x8E\xB5\17(Rl\xBFkw\xC8\xAB\xBB\x99\xBAX,`\30"
            "\x86\x93\xC3+\x96\35\0\x80\x97\x97\27'\10\xF9\10\22\x9D\xFE\1\xD1\xC9\42""b\xAB\xCE\14\xBB\xB3""e\xE1\xADt\xCD""1\xA0,KX\xEC"
            "\xCDQ\21\xE7\x91}\42\xB9LW\xF9\42\xCE\x83\0\0\xA3\xC3\x8C\x9A\xA5\xC9\25\xE7\xD9J\3(\30`7\xE6Y\xAEV\xA4X\xD0-,a\35@\xFC]\xF1"
            "\x9Cw\xD5""9\xE7\xF1\xFA\x8A\xC3\xEC\2\x8FMv\xDB\xED'\20\xA5\xB8\xAB~\xAD \xECj\6\x8F\30\x9C\30y'\x80\xC7\6\34\xDD\0\xCAys\x82"
            "\xE7\32\x84\x95x?P\xDF\xF7\xF0\xE3\xC7\x8F\xEC\x8DY.\x97\xF0\xF3\xE7O(\xD1\x9E\22\xE7\x98J\xDA\xE9\xFB>\xE8\\Q\7\0\xF0\xF4\xF4"
            "\x94\xADr%\17\x8D\xEDv;\xB8\xBB\xBB+\xD6\x9E\xA9\xD9\xA9*\16""d\xAA\\\xCE\xC3[\xB9\x97\x92R\x93\xE1\x9A\xECtj\x81""5\xED\xC8Rt"
            "P\x89\xF6L\xCD\x8E\xD7&\5\x9A""4I\xC5@\24g\xAB""6\x96\x89u\36K\xB4gjv\xBC\1$*\xA6\xBB\x9D\xC4X\x9F\xA5\xA2\xBA\xE8k\xAA\x98H"
            "\xA9\xF6L\xCDN\20\x80\x8E\7\xBC\xCC\xD7\xC5""5\xC6\xD2l9\5p\xF4\x9D\21\x7Fg\xBAT{\xA6""f'\xC8\7rUN\xADh\37y\x9Cu\xB5Z\1\42\30m"
            "\x8Ak\xA1\xF7\x86J\xB5gjv\x82\0\xE4S\xB9\24\x95\24\xE0\xA1\xDA\xF1\5\x91\xDC\x9E\xAF_\x8F\x87\15\xBF~=\xCF\xA3\xA6\x87\xB4\xA7"
            "T\xBF\xC9v\xC4s\2\xEA\xF3\2jz\16\20\x91wa\x8C\xE9+\xC8\22<\27\xE9\3\x9E\30\20\t\21\xCF!\xAA\xCF#\x9A\xD2""CE\xF4\x8F\xED\x93"
            "B\20\x8F""e\xA9}hJ\xCF\16\xA0\x90Y\x94\x92*S\x83Um\x8F\17\x80|\xDA\xA3""c\5\x9D?\xA2""c\x89P;\xA2\14\1\26\xB5l5=5\13q\37`\xE8"
            "\20\36\x8B\xEE\20\xF6\x89""e\xA1\xA7\xA7\xA3\xAEz\x87\xC0\x94\36""2\1|\x96\xE3X&\22\xB6t\xE3""c\2nq\0\x95\x94\\`-!2xd&\xD3\xB1"
            "\x9B\xF8\x9E\2""D\x97\x92\16n\\TzO\1~\x99\xD1t,\xA7""c\xB8k\5\21\xF7\xED\xE4\x90\xEB\xB5\x8A\xBC\xDB\x92\x7F_\xF3""d\xC8\xE1"
            "\xA4{\3h\30\x86O3\xD3T\31u\xBDg,.\xEA\x99\3\xACj{\xE4%D\xF6\23t\xBB/\x9F\xF6\xE8\xEC\xD8\xFA-\xB5\35\xB1\xCC\xCB\x9F\30;\xC9"
            "\x9Dh\35\xC2""ci\x7F\xBB\xDD""F\x81""5&*\xBD\xD9\x9C\xC7JRm\xDFK\xF4\33\xD5i\xCF\xBD""4r\37\x94\xEB\20\x9E\3\xDD""9:]\xD7\36"
            "\xE1\x8B\x88t\xD5""7\tiO\xA9~\x93\xED\xB8\xFA""E\16-\xA4\xBE\x9D\xC1""C\xA8\xDF""4\13""B+\xA7\xB2\20\xB5\xD3}\xD9\xC7""5\xB8"
            "\xA9\xDAS\xAA\xDFJ\xD9\x89Z\xC2""D%m\xCBJ\x8A\xCA\xE9@d\xEB\x8C\xD0\xA5\xABT{\xA6""f'j\33/\x8C\x8B\xA3\1\xBAk)\xE4\10\42\xDB"
            "\xDD\xF8\x8F|\xB1\x9D^\xA2=S\xB3\23\35\7*qxL\x80""C\0Iw-u\xC7\xE7\x96\xA9\xD9\xD1\2\xA8\x86W\xEE\xA6\4K;\0_Fx\xCD\x95k\x83Z7x"
            "\0\0\xBAR\17\xAF-\x97\xCB\42OqN\xF1\xA1\xBF\x9A'w\xECk\x94\x9B\xDC\xB6\xB0\xD3""6\36\t\37\x9D\xAC\35\x7FU\t\xB1""3\xB5\xBA\xD5"
            "\xAC\23\xD4o(\xDE\xCB""d\xF9\xC8\xF9\0\0\xD7\x9A\xEFk\xCD""5\x9DN\x88\35\37\35\14\xA8\33\xB5\17\xD6\x91:1\xED\xC9\xAD""C\35"
            "\xD3\xB5\x82\xBFO\5\x9A\14\xA1\2`\x9B""A\x97N\x88\35\xAA\16:@\xE4\xD2\xA1\0!T'\xB6=9u(c\xBA\xD6\20\xD8\xA7\x82\xC1\xD0Q\xAE""A"
            "\xA9""E'\xA4=.\35\33\10}tjiOH_\xAF]\14\xE4""c\xCC""f\xE8\xD2:9:\xDC\xC6@>:\xB5\xB4'\xA4\xAF\33\3""5\6j\14\xD4\30\xA8""1Pc\xA0"
            "\xA9""2\20\20""f\x86\17Z/\xA5\23\xD2\36\x8A\xCE\x9AP\xD7X\6*\xD9\x9E\xA4\14\24\32\xD3\xA9""9\16\x94""C'U\34(G\x8C*U\34\xC8\xA3"
            "=\xE7\1\xCB""5\xA1""a.Z\xF3\xA1h[%\xA7\xAC""3\xA1~+\xCB@\xA5\42\xB7""53])\6Z\x97""d\xA0R>P)\x9F\xA1""f_\xAB""f;\xD5\xEF\xC2J"
            "\xEDZj\xDE\xED\xD5l\xA7\xFA""8P\xA9\xB8I\xCD\xF1\xA6\x9A\xED""4\6j\14\xD4\30\xA8""1Pc\xA0\xC6@\xB7\xCA@\xB9\xCF\3\x95:?S\xEA"
            "\xACRM\xFD\x96\xFA\xEC\x95\xF7y\xA0\x9A\xE2\31\xA9\xE2@\xB9\xA3\xE4S\x8D\3y\x9FH\x9C""bD\xB5\xD5\xADH\xDD\xDAS\31M\xE2\x9E\xCA"
            "\xA8\xEA\xDD""b\xF3\16\x90s\x80\xB7""7\x80?\10\xAC\x8D\xCFu\t\xE5\x89\x8Fl\xD2)\xFF\x91\xFB\xAF\xFB\xDA\x98\xD1\xF4\xEA\xCF\\v"
            "\xAE\xE5\xB5\xA2\37\xE0\xB9\xA8t\xAC\xF6\xA5\xB4\4\x80\xF0\xEA\xDC\t>\x82\x87\21\x99\xC9\x94\xA6""c\xAD\xA4l\xD6""1\xC0\x8E\1"
            "\xFE\xF7\xDF\xF3\xF2""f\14\xF0\x9F\xBF\1;\xFE\x91>c\x80\xF3;k}\x8F,7\7\x9Cy\1\xD7\xF5""29\25""d\x94\xEFr\x9A\xCD\xA5""0\x95/"
            "\xA7\xD9^\x90\x9C\17\x9C\30\x90\xD7\xF4\xAF\xD8\xD1P&RAr\xC7\1\xE7\xDDy\xFE;e\x90\37\xC6\xEB\xEA\xE0\13\xD0\xFC\xFB\x8F\xF5_"
            "\xC5\37u\xA5\xF4\xFF\xFC""E\xA9\x9F\xEE\xB5\xDD>\xAF\xF8\xA6\0\xC8\x97\xA9\\\xE5\x97Xr\xC1""9S\xD1\xC0""8.\0""E\xF9T\xF2\x92"
            "\xD6\31\xF4\xFF\x9E+l\4Z`\31\xEB""2\xF3\xAA\x97m\x80L/\xE4s\xFD\xB5\x95oc\33\37\0\xE5\xF5\xA9\xD4W\xDC""1e9C)\xCDwW\xC4\42t"
            "\xE1\xE1\xC1\x9D\xE7\xF7o\xF2\x9ER[\x97w\0\xF6p\x97\xCA\xF7J\xF9\x86""f\xB5\14\xF5\xB5\xA3\x97\xAA\x97\36@%bA\xE8\xC3""8\0\0"
            "\xBF~I\xCC""2;\xCF{?\xFA;\xF3\xB9~\16w\x9D\xBB.\x82}~\xBD\1\xF3w\xE0]\xEF\x8C\x95\xDF\x8B*\xFB""6\xA6\x7F\x8B""B)\xB3~'\35\23."
            "aAN\xB4p\x94\xEF\xF8g\x9D\16\0;\0\x9C\xCF\24\xFFhvt\x84\37\xEE\xCF\x9Dh\x8A""C\xDFq\37'\xDA\xF5\xDF;L\xCB\x84\xAF\37""bZrB\x96"
            "\xB0""2Nt\x93&M\x9A\\J\6\xC0\xB3OlY\x97\10\xF1m\xEA\15""B\x8A\xBA\xE5\xAE\xA3\xE1""Fi!\0U\0\x82\xDC\0\xBA\24\xC8\xA8vc\xEB\x87"
            "\5\xEF&\xC8\xB6""84i\22!\xEE\27\x8D\xCB\x8C\xD4K\xF1\34\x95\xA9z`0\0~\xFA+\xEB\x99\xD2Mvt\xF9\10""3\x99m\x80\x89\31\xCD""6\37"
            "\xBA\xE2\x9A:\xE3\xD5""4Y_\xFD\xAD\x96\xA7\x96""ab\23\x97mj\x9EP\xC6`c\xFCK|W\31\x8BI\xF1""1\xF9\x9A\xAC\xA7\xFE>~\xB7\xF9@"
            "\xA6\xDF\xAEt\xB5,J:\xC5\16\x81\xFEq\3\xA8\xFE\xD6\xE5q\xF9)\xAE\xEF\x94""2(>\x90O\xFD|| \xD3\x92#\xBE\x9B\xF2P\xD2\xE5\xEF"
            "\x9D\x96\tlLC\25\23k\x98\xD2\23\xFA^\x94\31\x9B\xC2'\12-#\x97\xCF\xC6\14\21\x7F\x99q\30\xE1\xAE\x80\x8F?\xD5\5\3!\xB5\xF4""e"
            "\17\x90\xC5.\13\xA1""e\xC8\xCB\x94\15()\xEA\27\xDC.\x8F[O~Nt\xA9\35Z\xE1\x9D\xE0%\xD9\xA8\xD4\16M\xDC\14\xF3\xDD\xAD\xB9\xF2wV"
            "GYvx\xE5kjz\12\xF6""1\xD5!!\xE3\x88\xD9\xAFs\x92""C\xCBS\xCBP\xD3]z)\xEBgs\x8C]\xF9""E^\25""d\xBA""2D\36\6\xA9\xC6ih\7\xF3\xAF"
            ".v\x96\xEA\xA0_\22\xC0\xF4\xED\0\xFC\xAD\12\xFB\0$)\x9F\5\xD0\xD6|>\xE5\xA3G\xBDM6\x98\xE6\xB7O\xF9\xBE:%\xCBO1^\xC9\x84\23\33"
            "\x8C\x81\xD7 A\xF9)\xF2G\xB2\xFD\xC5\xCB\xC7\xCC\xFD\x99l\tc\31\xC0\xE1[>\13\xB0\x87\x81\xB3\x8F""E\xD6\37\22\xD5?\25\xD3\x94"
            "\x7F\34\xAB\xC0\xCCl\xFE\xD1\xC4} $\42\x9A%\x9C\xFDH\4\31""f\xF0""9|},L4I0\x82""9B\x98\xA6\xC8\xC4-}7\36=\xC0s\xE1]n\xB5>YU"
            "\xD2]p@B\xFC\t\xF9L6\13""d\xC6\x92>\x8A/\xFBP\xDA\33\xB3\xDB\xBDJ\0]\3\xE3""4I\4 \x8C\0\x86\x9C\26""2\xCBY\xA1Y\x84\x85u}|D,"
            "\xD0\x86\xE4>P\xEC\xD6\xF4R\xCE\x7F\xA9\xF2s\xF7O\x8E\xF2\x8B\x8D\xD7\xFF\1Ot\x9FI\xD2y\xAB\4\0\0\0\0IEND\xAE""B`\x82"
        };
    }
}
