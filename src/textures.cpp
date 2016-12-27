#include "textures.hpp"

namespace Resources
{
    namespace Textures
    {
        namespace Rectangles
        {
            const sf::IntRect cell[] =
            {
                {0 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {1 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {2 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {3 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {4 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {5 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {6 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {7 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {8 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {9 *CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {10*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {11*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT},
                {12*CELL_WIDTH, 0, CELL_WIDTH, CELL_HEIGHT}
            };

            const sf::IntRect smiley[] =
            {
                {0*SMILEY_WIDTH, CELL_HEIGHT, SMILEY_WIDTH, SMILEY_HEIGHT},
                {1*SMILEY_WIDTH, CELL_HEIGHT, SMILEY_WIDTH, SMILEY_HEIGHT},
                {2*SMILEY_WIDTH, CELL_HEIGHT, SMILEY_WIDTH, SMILEY_HEIGHT},
                {3*SMILEY_WIDTH, CELL_HEIGHT, SMILEY_WIDTH, SMILEY_HEIGHT}
            };
        }

        const Resource pack =
        {
            1317,
            "\x89PNG\15\12\32\12\0\0\0\15IHDR\0\0\0\xD0\0\0\0*\10\6\0\0\0\xC2\xAD\xD5\13\0\0\0\tpHYs\0\0\13\23\0\0\13\23\1\0\x9A\x9C\30\0\0"
            "\4\xD7IDATx\xDA\xED\\\xDBr\xAB:\14\x95\14\xD3\xFDY\21}\xE8o%\xFD\xAD>4\xCEg\x9DL\x82\xF7""Cq\xB6\17\xF1\15_\x88\xA1Z3\x99\26"
            "\x83\42.ZZ\x96 \xE0\xE9tR\xC0`l\24\xC7\xE3""1\xD9\xF6r\xB9\xC0\xE1p\xC8\xB2\xEF\1\0\x88(\xF9K\xA4\x94l\xCF\xF6Y\xF6\xC7\xD3)"
            "\x87""A\xC9\xC1/\xA5L&\x90\xB6\xEF""9\x87""1j\x82\x88@J\x99l\x8F\0\xA0\42\3z)qK\xD8\xF7\xF5O\xE0""ar\30\xB7\x83$\xFD\xD9L\x92"
            "\xFB""b\34\42""2\xE1%\xE2""b\x92\xE1""CJzZv\xEF\33""E\36\xA3LZ\27\xF2\21\xAB\4\xBE\x80\16\5{\x8E\xDAl\15:\x9E|1#\xD6 O\xF4\xF6"
            "\x92\x8Al\23sR\x9A\xCC\xD6\31\x99\xBA\4""b\x94\42\xB4\xCD\xC7\xC7\xC7\x83h\xC3""0\x80\20\2\x88\xE8""A\xBC""a\30\xBC\xF6\x7F"
            "\xDE\xDE\36\xCA#\20""A\10\1""8-\xC3""4\xB6\6qb\xE3\xA4o\x85<!\xA5\x89!\x8E/S\xC4\x9E\x90X\xB5\xA9M\6\x99@t_p/U\x8E\xF9\xF6\xB1"
            "\xD3\xB0\xAF\xAF\xAF\7I\x94R\xA0\x94\2!D\xF4t\xEE\xBF\xEB\xF5\x87$\x93\xADi\x8F\xE3\10J\xA9\xEA\xE4Y\x82\xBE%\xF2\xF8\xA6g\x8C"
            "\xED\xD4<\x9A<\0\0\x88\xF8 B\xDF\xF7""A\22\xE1\x8F\xB1\xD3\36o7\xA8I\xA1\x8B\x94\x8BHT\x85@\xBA\xDE\xC9U!\x9B\xF2\xC4\x92\xCCu"
            "\22.\xDE,-\xBD\xCBz,F\x99\\\12\22\xABL\xAE\xEDR\x94\xC9T\x93\x90J\xE9\xF5\xAE\xED""BJ\xA6\3~\xBE,\x84\x80\xDB\xED\6o\xD3\24-"
            "\xCB\xFEz\xAD\x9A\4t\x8C\xC4\20I4\x9B\xC9$%\x93\xA7""e\xC8\xCC\32\xEC\xD5u\x92\x8F|D\4""8\xD5(8\xD5/J)@D\30\xC7\21\xBA\xAE\x83"
            "\xEB\xF5\12""D\4\xEF\xEF\xEFO\xCA\x83\x93]\xC8\36\1\xA0\23\xF5""C\xF7\42%\x84*\xAE\xBE""E\xE2\x94\x98\xDA\xCD\x95""Fg\x93\3"
            "\x91S\x85\\\xCA\22[\27\xF9\x82{)q\xE6\xDB\xA7\22'V}\xE6\xEB]5\x90\xEB\xBE\x8F^OD\x8F\xC0\xD7\xC1\xAF\25\xE4~\xBF;\xF7""Ck\16"
            "\x8E""c\xD0^\1\0\x8C""c\23\xF1\xDA\xB7L\36\xAE\x89\xB6\t\xB3\xF8\37\15""B\xAC""e_\xB2\x96\13""5?Vk\42,\xBD\37\xE4R#\37\xB1^"
            "\xDD\xA2\x96\5\xFD\x97\x98\xAA-Q\37\x9F\32-\xB5#\42\xE8\xFB\36n\xB7\33t]\xF7P\16""D\x84\xF3\xF9\xEC'\17\0\xE0\xD4""0\xB0\xD9"
            "\x8F\x95\x89\xE4\xAA\xF1\xF4\xF8\xFC\xBC""4[\3\xD5.\20_\xA7\xB2y\xD3<Y1I\xC4\xB4\xBA""C\xDB\14\xC3\0R\xCAG\xC1\xAF\x83\37\0"
            "\xE0|>\7\xED\5\42(\0\xAB\xFD\xA8\24`c\xF1T\xB5\13\xB7<\x83\xCB&\xC9\21{?\xA8\x84j\x94$H\x8A\x8A\xE4>i\xA0\25\xC6\xAC\x89\xCC"
            "\xFD\10\xED\x93V\30\5\0""05\14\x94\xA5V\xAA""6\x8BXx\xCE\xF8Y8FU\x88\xCCn\x99\20\42\xD8""0\xD0\17v&'\xDE\14{\xC1\x97\x98Q\23"
            "\xDF\xDF\xDFY\xF6\xF7\x86\xC9\3\0\x80k\xFC\36(\xF7\x89\xDC\xDF\xEC\x87\x88\x90i\xD8.z\x80\xBC\37%-a8\xFBY/32V\x9A\xA2\xD6\xFC"
            "\xF2\xB5\x82\x80\xFD""0^\xAA@\xE6\x85+\tW\20\xB0\x9F""4?\x8C_\xA6@\14\xC6\xAFR\xA0\x98\xA2v\x8Dl\xC9~\30\xBB\42\xD0\xBF\xDFx<"
            "\xAF""C\xA4""b\1\xC1~\30\xBB\x9B\xC2\21\21(e\17\2\35\34J\xE5\xDF\xC1""f?\x8C\xDD\21H\7""A\14r\x82\x81\xFD""0\x89vG\xA0%A\x90"
            "\23\14\xA6\x9F\xCFO\0\xC4\x9F\xBF&\xE6\xE3\xB9~\xD6:\36\xFD\xFE\x8B\xF9{0\xE6\xE3L\xA2\35O\xE1\xCC\x8Bn\13\x84\x92/I\xD1\xEF"
            "\xD7\x9B\xBFg\xCF""5\x9E\12\xBD\xDF\xBEO\t(\xF5\xF3]s\xE2\xBA\xC6\31;!PJ\xB6N\xC9\xDAs?K\10\x94\xEA\xC7""F\16{\x91\x9F\x7F<"
            "\x9A$\xB6\xC4""3\37g\25\xDA&\xFA%\xC4\x88\31\xCB\xC1\xF1h\x7FS\xABk<Eyl\1\xBD""D=\x96&\23\xDByr\x8D""3v<\x85\xDB:L2\x98JfS7"
            "\xFD\x7F,\xD9\30\xAC@M\6|I\xA5""3\xBF\xC3\xA6h.\x95""c\22""1\xB2\25(\24@\xA5\3\xCC\xEC\xB6\x99\xCB[V\xBF\32M\12""F\xA3\4\x92R>"
            ")\x80\xEB\xA2\xCF\xEB\4\xC4\xF8\xBB\xEBs?\xE6\24\xCA\xAC\23l\xDD\xB7\\?\xBE\xE3)\xEDG\xDF""45?9~\30\33m\42\xC4v\xB0rq:\xFD\xBF"
            "\xE0/\xD5\xBE^\xFBx|M\10ne\xEF|\12g\xCB\xA6\xB6L\x9A\x9B""Em~t-\xA2\xC7\xE7\xB5I)?\xB5\x8F'D\16\xB3\xB5\xCE\xEA\xB3\xC3\32\xC8"
            "5\xC5re\xDB\x9Cw\x89\xF9\x82\xBB\xA6\x9F\xB5\x8E\xA7\x86\37\xC6\6\x9A\10:\30|5C\x89 `?\x8C\xDD\xD6@\xFA\42\xEBG\xF0m\xEBJ\x80"
            "\xFD""0v\xDB""DX\xF3\xA2\xB3\37\xC6\xE6\10\xC4/\xE6h\xDB\17\xA3MtDtB\xC4U\x82\x80\xFD$\xA9\xD7'\x87i\xC3M\4~\xE9""a\xDB~\30m"
            "\xE3/[\xC4\xE4""f\xDB\xF7\xE8\35\0\0\0\0IEND\xAE""B`\x82"
        };
    }
}
