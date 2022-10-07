#include "interpolating_resampler.cc"
#include <iostream>

using namespace gr::digital;

int main()
{
    auto d_interp = interpolating_resampler_fff::make(ir_type::IR_MMSE_8TAP);

    std::vector<float> input_sig;
    for (int i = 0; i < 100; i++)
    {
        input_sig.emplace_back(i);
    }

    d_interp->sync_reset(30.5);
    std::cout << d_interp->interpolate(&input_sig[30], d_interp->phase_wrapped()) << std::endl;
    d_interp->advance_phase(8.3);
    int imu = (int)rint(0.8 * 128);

    std::cout << d_interp->interpolate(&input_sig[38], 0.8) << std::endl;

    // float output = d_interp->interpolate(&input_sig[30], mu);
}