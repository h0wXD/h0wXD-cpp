
#ifndef H0WXD_IO_VIRTUALFILESYSTEM_REPOSITORY_H
#define H0WXD_IO_VIRTUALFILESYSTEM_REPOSITORY_H

#include "IVirtualFile.h"

namespace h0wXD { namespace IO { namespace VirtualFileSystem {

    class Repository : public IVirtualFile
    {
        public:
            Repository();
            virtual ~Repository();
        protected:
        private:
    };

}}}

#endif // H0WXD_IO_VIRTUALFILESYSTEM_REPOSITORY_H
