#ifndef ATG_ENGINE_SIM_DYNAMOMETER_H
#define ATG_ENGINE_SIM_DYNAMOMETER_H

#include "scs.h"

#include "crankshaft.h"

class Dynamometer : public atg_scs::Constraint {
    public:
        Dynamometer();
        virtual ~Dynamometer();

        void connectCrankshaft(Crankshaft *crankshaft);
        void connectBody(atg_scs::RigidBody* body);
        virtual void calculate(Output *output, atg_scs::SystemState *state);
        double getTorque() const;

        double m_rotationSpeed;
        double m_ks;
        double m_kd;
        double m_maxTorque;
        double m_clutchPressure;

        bool m_hold;
        bool m_enabled;
};

#endif /* ATG_ENGINE_SIM_DYNAMOMETER_H */
