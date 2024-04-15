#include "dg_cat/datagram_source.hpp"
#include "dg_cat/udp_datagram_source.hpp"

std::unique_ptr<DatagramSource> DatagramSource::create(const DgCatConfig& config, const std::string& path)
{
    if (path.compare(0, 6, "udp://") == 0) {
        return UdpDatagramSource::create(config, path);
    } else {
        throw std::runtime_error("Unsupported protocol in path: " + path);
    }
}