classdef SmoothedMute < matlab.System

    % Implementation of a smoothed mute function for audio processing
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Copyright 2022 The MathWorks, Inc.

    % Public, tunable properties.

    properties
        Tau = 0.1;
        SampleRate = 44100;
    end

    properties (DiscreteState)
        currentGain;  % the current gain
        muteState; % 0 = No mute, 1 = Muted, 2 = Muting, 3 = Unmuting
    end

    properties (Access = private)
        % Pre-computed constants.
        Ts;
    end

    methods (Access = protected)

        function [y, gain] = stepImpl(obj,u,Mute)

            % Implement algorithm. Calculate y as a function of
            % input u and discrete states.

            % Add some 1st order smoothing
            % Tau = Time constant
            % Ts = Time step
            % a = Ts / (Tau + Ts)

            if(Mute && (obj.muteState == 0)) % Not muted state, mute turned on
                obj.muteState = 2; % Change to process of muting
            elseif (Mute && (obj.muteState == 3)) % Process of unmuting state, mute turned on
                obj.muteState = 2; % Change to process of muting
            elseif (~Mute && (obj.muteState == 1)) % Muted state, mute turned off
                obj.muteState = 3; % Change to process of unmuting
            elseif (~Mute && (obj.muteState == 2)) % Process of muting state, mute turned off
                obj.muteState = 3; % Change to process of unmuting
            end

            frameSize = size(u,1);
            y = zeros(size(u));

            gain = obj.currentGain;

            switch(obj.muteState)
                % not muted
                case 0
                    y = u;

                    % muted
                case 1
                    % do nothing, we've already initialized y to zeros

                    % muting
                case 2
                    a = obj.Ts / (obj.Tau + obj.Ts);

                    for i = 1:frameSize
                        gain = gain * (1-a);
                        y(i,:) = u(i,:) * gain;
                    end

                    % check to see if we're fully muted yet (-120db)
                    if(gain < 1e-6)
                        obj.muteState = 1;
                    end


                    % un-muting
                case 3
                    newGain = 1.0;
                    a = obj.Ts / (obj.Tau + obj.Ts);

                    for i = 1:frameSize
                        gain = gain * (1-a) + newGain * a;
                        y(i,:) = u(i,:) * gain;
                    end

                    % check to see if we're fully un-muted yet
                    if(gain > (1-1e-6))
                        obj.muteState = 0;
                    end
            end

            obj.currentGain = gain;

        end

        function resetImpl(obj)
            % Initialize discrete-state properties.
            obj.muteState = 0;

            obj.currentGain = 0.0;

            % Calculate timestep
            obj.Ts = 1 / obj.SampleRate;
        end
    end
end
