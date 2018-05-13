clear all
a = arduino();
i = 1;
tid = [0];
figure
while true
    sF(i) = 1/(readVoltage(a, 'A0'));
    sL(i) = 1/(readVoltage(a, 'A1'));
    plot(tid, sF, 'b', tid, sL, 'r')
    pause(60);
    i = i + 1;
    tid(i) = i;
end