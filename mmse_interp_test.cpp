#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gnuradio/filter/interpolator_taps.h>
#include <gnuradio/filter/mmse_fir_interpolator_cc.h>
#include <stdexcept>
#include <iostream>
// using namespace gr::filter;
// gnuradio/gr-filter/lib/mmse_fir_interpolator_ff.cc
namespace gr
{
    namespace filter
    {
        namespace
        {
            std::vector<kernel::fir_filter_ccf> build_filters()
            {
                std::vector<kernel::fir_filter_ccf> filters;
                filters.reserve(NSTEPS + 1);
                for (int i = 0; i < NSTEPS + 1; i++)
                {
                    std::vector<float> t(&taps[i][0], &taps[i][NTAPS]);
                    // std::cout << t.size() << std::endl;
                    filters.emplace_back(std::move(t));
                }
                return filters;
            }

        } // namespace
    }     // namespace filter

} // namespace g

int main()
{

    std::vector<gr::filter::kernel::fir_filter_ccf> filters = gr::filter::build_filters();

    std::vector<gr_complex> input_sig;

    for (int i = 0; i < 100; i++)
    {
        input_sig.emplace_back(gr_complex(i, i));
    }

    // for (std::vector<float>::const_iterator i = input_sig.begin(); i != input_sig.end(); ++i)
    // {
    //     std::cout << *i << ' ';
    // }

    float mu = 0.5;
    int imu = (int)rint(mu * NSTEPS);

    if ((imu < 0) || (imu > NSTEPS))
    {
        throw std::runtime_error("mmse_fir_interpolator_ff: imu out of bounds.");
    }

    std::vector<float> output(100);
    for (int i = 0; i < 100; i++)
    {
        std::cout << filters[imu].filter(&input_sig[i]) << std::endl;
    }

    // float r = filters[imu].filter(&input_sig[30]);
    // std::cout << r << std::endl;
    // return r;
}

//  d_interp->interpolate(&input_ff[10], 0.5);
