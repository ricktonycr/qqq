/*
Copyright 2005 - 2017 by Paolo Brandoli/Binarno s.p.

Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement 
 that your application must also be GPL), you may purchase a commercial 
 license for Imebra from the Imebra’s website (http://imebra.com).
*/

/*! \file baseStreamOutput.h
    \brief Declaration of the the base stream class BaseStreamOutput.
*/

#if !defined(imebraBaseStreamOutput__INCLUDED_)
#define imebraBaseStreamOutput__INCLUDED_

#ifndef SWIG

#include <memory>
#include "definitions.h"

namespace imebra
{
namespace implementation
{
    class baseStreamOutput;
}
}

#endif

namespace imebra
{

///
/// \brief This class represents a generic output stream.
///
/// Specialized classes derived from this one can write into files on the
/// computer's disks (FileStreamOutput) or to memory (MemoryStreamOutput).
///
/// The application can write into the stream by using a StreamWriter object.
///
/// While this class can be used across several threads, a StreamWriter can
/// be used only in one thread.
///
/// Several StreamWriter objects (also in different threads) can use the same
/// BaseStreamOutput object.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API BaseStreamOutput
{
    BaseStreamOutput(const BaseStreamOutput&) = delete;
    BaseStreamOutput& operator=(const BaseStreamOutput&) = delete;

#ifndef SWIG
    friend class TCPStream;
    friend class StreamWriter;
    friend class FileStreamOutput;
    friend class MemoryStreamOutput;
    friend class Pipe;

private:
    /// \brief Construct a BaseStreamOutput object from an implementation object.
    ///
    /// \param pStream the implementation of BaseStreamOutput
    ///
    ///////////////////////////////////////////////////////////////////////////////
    explicit BaseStreamOutput(std::shared_ptr<implementation::baseStreamOutput> pOutputStream);
#endif

public:
    /// \brief Destructor.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~BaseStreamOutput();

#ifndef SWIG
protected:
    std::shared_ptr<implementation::baseStreamOutput> m_pOutputStream;
#endif
};

}

#endif // !defined(imebraBaseStreamOutput__INCLUDED_)
