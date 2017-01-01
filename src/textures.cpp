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
            2583,
            "\x89PNG\15\12\32\12\0\0\0\15IHDR\0\0\0\x90\0\0\0q\10\6\0\0\0:^*\x9F\0\0\0\tpHYs\0\0\13\23\0\0\13\23\1\0\x9A\x9C\30\0\0\t\xC9ID"
            "ATx\xDA\xED]\xEDn\xDB:\17\xA6""4o\xEF""e\xD5I\x80\xDDT\16\xD0\24XojCR\7\xBB\xAA\xD3\xAD\xD1\xFB\xA3\x91\x8F\xAA\xEA\x83\xA2$Zq"
            "D Xc\x8B\xA2>\36=\42);\23\x87\xC3""AA\x97.D\31\0\0\xC6q$W0MS\xD7\xBF""c}\xD9\xD7P\x97l\6\xAA)\xE3\xF8pE\xFA\31W~\12\xAF\x86i"
            "\x9C\xBC\xF7\36\20+\xE9<M\x88""6O\xC6\12\35?}\xF7\xB7mD\xF6q\42\xDD\x8B\xD9\xC0""2\xC9\24\xB0""1E\xEC\xDB""6$\7x\xD0\xE5\xA7"
            "\xB1H\x99\x90<\x8C""c\xB3\xAByD\x80\xBB\xA6L\10\xFBv\x99\xA1\25\xF0\xC4\x98\6\3\x9C\20\xBB`\x81\x83""e\x9B\xDA`\x98\10@\17\1 "
            "\xD5\xCF\xB1\xCB\xFB\xEA\36Z\2Oh{\xEArG>\x90\xF6wrY\xC8\xC5<X\x90\xF9\30\xE7\34\\\xA5S\xF0\xBB\xBE\x86""a&\37\x83`\x99\xC9W"
            "\x8E\xC2L&\x9B\xC4XJ\xDF\xF7\x95""c\xF5\x81r\x81""C\5O\xCB""2e\xFA`K\xFBI\xECQX.\xE3P\x81""c3\x8D""f\xA4\x87q\xF4\xB2\x90\x8FY"
            "\xB0~QhrS\x81""c\x97\xA7\2\7\xCB>\xF6}\x9F\17""d\xE7\x8D\x86\x96\xC1\xD3}\xA2;\xF5\x81\\\xBEOj>(\24y\xF9\x80\xB5t\x88>\25\xB4_"
            "b\xABJa\37JH\xDF\xB4\17TK\xCE\13\xFB\20\xB9\xDB\xDCTq\x91`B}\xBBL\xD5(\x8C;\x8C\xAF\5\16l>\xA8\4k\x94\4\xC8""DhOj\xBE\xA8\x9F"
            "\x85u\xC9\x92\16\xA0.Y\42\x94R\xE4\xE7\x81\xCE\xE7""3<<\xD0\x93\x85\xE7\xF3\x99""D\xB3%\xE5\xCF\x9F?Y\xFA?~\xFC \xEB\x9EN'8"
            "\x9DNY\xF6\x9F\x9F\x9F\xC5MFaz\xF2\xA9\0""2\xC1\x93\xFB<\xCB\xE3\xE1@\xD6\xFFg\xBF\x87\xEDv\xCB>\xF0&xr\xEC???\xB7\21\xC6\x9F"
            "\xCF\xE7\xE4\x89\xB3\1Q\xC3\xC1""3\xD3\xEB$\x8A\5\x80\x9CG.w\xBB\35\34\x8FG\24 R\1\xB4\6\xA9\x9AH\xD4y\x99sc\xE9w\x97lw\xBB"
            "\xF7\x89""E\x80\5Svw-\xA3\5\3\xC2\xEE""D\33\xC0\xA1&\xF5\xBE\x7F\xFF>3\xCF""f\xB3\1)%\x8C\xE3""8os\x9B\xCD&\xA8\xFF\xBFo\xDF"
            "f\xE6\x91""B\x80\x94\22\xC4\xF5;\\\xAF""9\31\xE1:\xC1\32\34\xBB\xDDn\6\x81\xF9w\12x\x8E\xC7\xE3\14\34\33PX\xF6""3?w\1\xA0\xDCl"
            "\xF0\xCF\x9F?g\x90(\xA5\xE0r\xB9\x80\x94r\6\xD2\xCB\xCBKP\xFF\xDF\xD7\xD7\31$\xB6\xBE\0\x80K f\xB0""A\x94\xC3R\xB9R\12\x84""7"
            "\7\xA0\xDC\xEDj\34GPJ\xCD\37\23\10\xC3""0D\35nq-\xEF\xD3\x8F\x85,\xFA\xBE\xBA\xEA\x81\xF1\xDD\xBC\37\22s\xD2\xD7.U| \15\42\12"
            "\33\t!>L\x9C\xFE.\xA5\x84\xBF\x7F\xFF\xC2\xB7\xEB\26\x95\xA5\xFF\xFA\x8As\xBC""5\x93%\x80'\xC4$)r+\0\xAC\xEA""D\x9F\xAFG\xFF"
            "\23\x92y\0\0\xA4\x94\xA0\x94\2!\xC4<\xF9""B\10\xB8\\.\xF0\xE5\xCB\27x}}\x85q\34""AJ\xF9!\x92""1}\x9C\x98\xBE\xB8\xDAy\xBB\\"
            "\xBCN\xAF\6\x91\13<XPP\xC1S\xAB\x9E\x9B\3\20%\xAC\xD7\xE0\xD0[\x90\xC9 ooo\xDE\24\xC0<\xD1W\x9F'\xA4\xAF\0\0\14\xF0\x98\x93"
            "\x83\xF1""38'\xB2""e\xF0T\5\x90\xE9\xAB\xA4\xE6r\xF4\xE4K)g'8%a\x9E\xABoo[\x9A\x89R\xB7\xB0{\xF0\x83""d\15\xE0\xB8\34]\xDFu\27"
            "\23)\xA5`\30\x86y\xDB\xB9\\.3\x9B\xC4\x80\xA8\x9D_\x9F\xBE""BL\xBA\xBDm\x99\x8Eu\12(J\x84\xDF\xAD;\xE4\xCD\35\xA6n6\33\x98\xA6"
            "ivx\xF5\xB6\3\0\xF0\xF2\xF2\22\5\xA1\xBC\x82\xC4\xA5\x7FQ*\xCA\42:T\27\x9E\xE8l\xCB\34J\xB7\x9C\3\xAA\xB2\x85\xE5\36\x8E\xEA<"
            "\x8F\xE9\23\x99u\xC6\xEA\xD7y\36\5\0pu\x98\x95""ck\x8A\xE5y\x8E\xC6\4j\6""8]\xCBlw;T.\xE8\36\xB6\xB0\1 \xFFT\xBC\xE6\xA9\xBA"
            "\x94""2_\xDFr\x98""c\xE0\t\xC9\xE9x\xFC\4\xA2\22\xA7\xEA\xB7\12\xC2\xA1""e\xF0\xE8\xC9\xC9\x91""7\4xB\xC0qM\xA0Y\xB6&xnA\4\xC7"
            "\xEF\3\x8D\xE3\10\xBF~\xFD\xAA\xDE\x99\xEDv\13\xBF\x7F\xFF\6\x8E\xFEp<\xC7\xC4ig\34G\xD2sE\3\0\xC0\xE3\xE3""c\xB5\xC6q>4v:\x9D"
            "\xE0\xEB\xD7\xAFl\xFDY\x9B\x9D\xA6\xF2@\xBE\xC6\xD5|x\xAB\xF6V\xC2\xB5\30n\xC9\xCE`W\xD8RDVb\x80""8\xFA\xB3""6;IA\12t\xE9R\x8A"
            "\x81""0\xCEVk,\x93\xEB<r\xF4gmv\x92\1\xA4\33\xE6:N\22""b\xAC\xD2PW\xF6\xB5TN\x84\xAB?k\xB3""C\2\xD0\xFB\3^\xFE\xFB\xFA\x9E\20"
            "eBN\15\34\xF7`\xE4\x9FLs\xF5gmvH>P\xACqvC\xC7\xCC\xC7Yw\xBB\35(\5^\x9B\xFA\36\xF5l\x88\xAB?k\xB3""C\2PJ\xE3J4R\x83\7k'\25""Df"
            "\x7F\x9E\x9E\xDE\37""6|z\xFAX\xC6\xBEN\xE9\17\xD7\xB8\x99v\xF4{\2\xF6\xFB\2\xF6\xF5\32 BGaB\xB8\33(\12\xBC\27\x99\2\x9E\34\20i"
            "\xD1\xEF!\xDA\xEF#\xFA\xAESE\x8FO\xE8SB\x94z\xAF\xCB\36""C\xDF\xF5\xEA\0\xA2\xAC\xA2\x92TY\32\xACv\x7FR\0\x94\xD2\37\27+\xB8"
            "\xFC\21\27KP\xED\xE8:4X\xEC\xBA\xED\xEB\xA5YH\xA6\0\xC3\x85\xF0\\tS\xD8'\x97\x85\36\37\xDFu\xED\23\2\xDFu\xCA\2H\xD9\x8Es\x99H"
            "\xDBr\xCD\x8F\17\xB8\xEC\0\xE2\x94Z`\xE5\20\23<&\x93\xB9\xD8M\xFF]\2""DK\xC9\0w.6\xBD\x97\0\xBF\xC9h.\x96s1\xDC\xAD\x82H\xA6"
            "\16""2\xE5~\xAB""bF[\xE6\xF7[^\14""5\x9C\xF4""d\0M\xD3\xF4ie\xFA\32""c\xEF\xF7""B\xE4""e=k\x80\xD5\xEE\x8F\xB9\x85\x98~\x82+"
            "\xFAJ\xE9\x8F\xCBNh\xDCJ\xDB\xD1\xDB\xBC\xF9\xC9\xB1S\xDC\x89v!<\x97\xF6\x8F\xC7""c\26Xs\xB2\xD2\x87\xC3\xC7\\I\xA9\xF0\x9D""c"
            "\xDC\xB0N{\xED\xADQ\xA6\xA0\xDC\x85\xF0\32\xE8\xAE""1\xE8\xAE\xFEh_D_\xB7}\23J\x7F\xB8\xC6\xCD\xB4\23\33\27""3\xB5P\xFA""8CR"
            "\xA8\xDF\xB7\12\xA8\x8D\xB3Y\10;\xE8\xA9\xEC\23\x9B\xDCR\xFD\xE1\32""7.;Y[\x98ndh[)\xD1""8\27\x88""B\x83""A\xDD\xBA\xB8\xFA"
            "\xB3""6;Ya\xBC""6\xAE\37\15p\xDD+!\xEF \12\x9D\xC6\xFFW.w\xD0""9\xFA\xB3""6;\xD9y \x8E\x87\xC7""484\x90\\\xF7J\17|mY\x9B\35'"
            "\x80Z\xF8\xC9\xDD\x92`\xE9\17\xC0\xF3\x88l\xB9q}R\xDB\6\17\0\xC0\xC0\xF5\xF2\xDAv\xBB""ey\x8Bs\x8D/\xFD\xB5\xBC\xB8s\x7F""F"
            "\xB9\xCB}\x8B\x98\xC3x\x85\xF8\xB8""d\37\xF9\xD7\26\x8A\x9D\xB5\xB5\xAD""e\35\xD2\xB8)\xFD\xBBL\x81\x8FY\16\0\xD4\xDE\xF1\xF7"
            "\xDEq\xCF\xA5""C\xB1\x93\xA2\xA3\10m\xC3\x8E\xC1>S'\xA7?\xB5u\xB0s\xBA\xB7\xF0\xF7\xA9""B\x9F!e\1""8d0\xA6""C\xB1\x83\xD5Q\21"
            "\20\xC5t0@\xA0\xEA\xE4\xF6\xA7\xA6\16""fN\xF7\16\2\xFBT1x\6*6)\xAD\xE8P\xFA\23\xD3\t\x81""0E\xA7\x95\xFEP\xC6z\37""c\xA0\24""c"
            "!CK\xEB\xD4\30\xF0\20\3\xA5\xE8\xB4\xD2\37\xCAXw\6\xEA\14\xD4\31\xA8""3Pg\xA0\xCE@ke @\xAC\x8C\24\xB4.\xA5""C\xE9\17""Fg\x8Fhk"
            ".\3q\xF6\xA7(\3Qs:-\xE7\x81j\xE8\x94\xCA\3\xD5\xC8Q\x95\xCA\3%\xF4\xE7""c\xC2r\x8F\xE8X\x8C\xD6R(:\xD4\xC8""5\xEB\xACh\xDCx\31"
            "\x88+s\xDB""2\xD3q1\xD0\x9E\x93\x81\xB8| .\x9F\xA1""e_\xAB""e;\xCDGa\\QK\xCB\xD1^\xCBv\x9A\xCF\3q\xE5MZ\xCE""7\xB5l\xA7""3Pg"
            "\xA0\xCE@\x9D\x81:\3u\6\xBAW\6\xAA\xFD<\20\xD7\xF3""3\\\xCF*\xB5""4n\xA5\x9F\xBDJ~\36\xA8\xA5|F\xA9<P\xED,\xF9Z\xF3@\xC9O$\xAE"
            "1\xA3\xDA\xDB\xC6\xD2\xB6\xFEVF\x97\xEC\xB7z\xBAt)\x83 \xD5\xD1\xD5\x85*}\33\xEB""Bf \25""a\33\xE5`%\xE5\xA8#\xC4h\x9D\xCD:"
            "\xFB|(\xEB\xFB\xAF\xD8\x95\xA7\xCE\xCEp+\x95!\x91m\xFA\xB6\xD8%\10 \xE1`\22""A\4""E\xDF\xB6\xEE@$\xF0\xE4\x82:\33\xAD\x9C\x81|"
            " \xA2\x82Kt'\xBAK\x97.]\xBA\xD4\25\xD7\26\x95\xB3\xDD(Xf\xBBZ\xCAnJ\xDBj\xB7Q-\25\xC8\xAC!g\xA3\12\x95Y2\x80PLv\x8A\xF6IB\x97."
            "\5\xA2""0,\xB2""c\x87\xAF\xCA\xF1\xAF\xA9\xE7\xBB\xEE\xB3\xA3\10T\34\xB3!\x90\xF6r\x8EkTd\x9B\15\xE9\xC5\xCA\xE4n\xF1\12\xE1"
            "\xBA`\xE6""b\xAE""3\xF4\xBB\x8B\xBE\xEF\xB1\xEBv]\x98\xEB\30;\30\x90""cl`\xECQ\x8FkR\xFB\x92\xD2\xBE\xD8\30`\xE6\xB1""D\xFB"
            "\x95\xCD@\42\xE0\x90R\xF7V\x91x\xBD\xE4\36.\22""A\xC7\xEDw\xD4\xF2\xD9\4\42X*:6C\xA1\xC9\xE0\x9A\xF4\xD6\xEC\t\42x0\13t\xC9"
            "\xA8\22m[2\xAD\xB8\x96#\x8A\xA5\xD9\x88+B\23@;YP\30\6\xF2""9l\xBE#\x89\xD2\xE7g\34G\37\42""0\x90\xA2`\x9B""cc\23;6\xCAi_jN\17"
            "\xD3~\21i\xEBM2F\x97""F\xE6l(d\xBC\37\x96\xDE\xA9\xA4""D[X:\xA4""FY\xA9\x91\x9F@P\xB2\xCA\xA8?g|\24\xC3\xF8\xE7\xCEW\21\x91"
            "\x85\xC2J\x95\xA1K\xA5\xD4""ER\xF7\13\xD6\xAF\30\xD2\0""E\xB6""0Q\1\34\xA9\xF5\13\x82=\xAAS,2\xDB\17\x85\xDA_\x8AiX\xFD\xD1"
            "\x81iev\37i\xE5>\x90""B\42Z\24\\\xFDXG\34\x93hS\31\xFD\xAD\xE9\x93\xA5\x8CS\15\xA6\xA9\xBEp\x97""8\x8DW7\22\xC5\xB5\xEC\x93""5"
            "#\xC3\xC2\23""B\xF1'\\o\x8C\xA4""2#\xA7\x8F\x92\xCA>\x98\xFE\xE6""D\xBB""7\t\xA0\x9E""7\xBA#\6R\31\xC0""0\xAFQV\xB9`ZE\x8AY7"
            "\xC5G\xE4z\x82\xB1\xA8\17\x94\33\x9A.\31\0p\xD4_{|j\xD4\xCF""2_\xFF\7U7\xB5+\xA6\xDE;\33\0\0\0\0IEND\xAE""B`\x82"
        };
    }
}
