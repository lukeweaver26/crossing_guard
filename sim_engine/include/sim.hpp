#ifndef SIM_HPP
#define SIM_HPP


namespace TrafficSimulation {
    class Engine {
        public:
            void loop();

            // Engine();

        private:
            const double TIMESTEP_SEC = 0.5;
    };
}

#endif