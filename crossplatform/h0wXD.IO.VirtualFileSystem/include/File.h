
#ifndef H0WXD_IO_VIRTUALFILESYSTEM_FILE_H
#define H0WXD_IO_VIRTUALFILESYSTEM_FILE_H

#include "IVirtualFile.h"

namespace h0wXD { namespace IO { namespace VirtualFileSystem {

    class File : public IVirtualFile
    {
        public:
            File();
            virtual ~File();
        protected:
        private:
    };

}}}

#endif // H0WXD_IO_VIRTUALFILESYSTEM_FILE_H
