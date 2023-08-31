#include "pch.h"

//  Models, Animations and Collisions:

ModelInfo* MDL_Spyro = nullptr;
ModelInfo* MDL_Isaak = nullptr;
ModelInfo* MDL_Lyle = nullptr;
ModelInfo* MDL_Jed = nullptr;
ModelInfo* MDL_Bruno = nullptr;
ModelInfo* MDL_Cleetus = nullptr;

AnimationFile* ANIM_Spyro = nullptr;
AnimationFile* ANIM_Isaak = nullptr;
AnimationFile* ANIM_Lyle = nullptr;
AnimationFile* ANIM_Jed = nullptr;
AnimationFile* ANIM_Bruno = nullptr;
AnimationFile* ANIM_Cleetus = nullptr;

CCL_INFO COLLI_Spyro = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 6.0f, 0.0f }, 6.0f, 3.0f, 0.0f, 0.0f, 0, 0, 0 };
CCL_INFO COLLI_Isaak = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 15.0f, 0.0f }, 7.5f, 12.5f, 0.0f, 0.0f, 0, 0, 0 };
CCL_INFO COLLI_Lyle = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 12.5f, 0.0f }, 7.5f, 10.0f, 0.0f, 0.0f, 0, 0, 0 };
CCL_INFO COLLI_Jed = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 12.5f, 0.0f }, 7.5f, 10.0f, 0.0f, 0.0f, 0, 0, 0 };
CCL_INFO COLLI_Bruno = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 15.0f, 0.0f }, 7.5f, 12.5f, 0.0f, 0.0f, 0, 0, 0 };
CCL_INFO COLLI_Cleetus = { 0, CollisionShape_Capsule, 0x77, 0, 0, { 0.0f, 12.5f, 0.0f }, 7.5f, 10.0f, 0.0f, 0.0f, 0, 0, 0 };


//  Values:

//  NOTE: Each dragon has it's own NJS_POINT3 value so I can set up individually the twp->pos + offset value for the smoke effect position in their execs.
//  Using the same one results in the smoke effect using the twp->pos of the first triggered dragon. So it needs to be manually set per exec.

#define SPEED_Dragon twp->scl.x

NJS_POINT3 SCALE_Dragon = { -0.04f, 0.04f, 0.04f };

NJS_POINT3 POS_IsaakSmoke = { 0, 0, 0 };
NJS_POINT3 POS_LyleSmoke = { 0, 0, 0 };
NJS_POINT3 POS_JedSmoke = { 0, 0, 0 };
NJS_POINT3 POS_BrunoSmoke = { 0, 0, 0 };
NJS_POINT3 POS_CleetusSmoke = { 0, 0, 0 };

NJS_POINT3 VELO_DragonSmoke = { 0, 0, 0 };


//  Spyro - Main:

void DISPLAY_Spyro(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;
    
    NJS_ACTION ACTION_Spyro = { MDL_Spyro->getmodel(), ANIM_Spyro->getmotion() };

    njSetTexture(&TEXLIST_STP_Dragons);
    
    njPushMatrix(0);
    
    njTranslate(0, twp->pos.x, twp->pos.y + 7.0f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScale(0, -0.02f, 0.02f, 0.02f);
    
    SetupChunkModelRender();
    njCnkAction(&ACTION_Spyro, SPEED_Dragon);
    ResetChunkModelRender();
    
    njPopMatrix(1u);
}

void EXEC_Spyro(task* tp)
{
    if (CheckRangeOut(tp))
        return;
    
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:

            tp->disp = DISPLAY_Spyro;
            CCL_Init(tp, &COLLI_Spyro, 1, 4u);

            twp->mode++;

            break;

        case 1:

            SPEED_Dragon += 0.33f;

            break;
    }

    EntryColliList(twp);

    tp->disp(tp);
}


//  Dragons - Display Functions:

void DISPLAY_Isaak(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    NJS_ACTION ACTION_Isaak = { MDL_Isaak->getmodel(), ANIM_Isaak->getmotion() };

    njSetTexture(&TEXLIST_STP_Dragons);
    
    njPushMatrix(0);
    
    njTranslate(0, twp->pos.x, twp->pos.y + 2.0f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScaleV(0, &SCALE_Dragon);

    SetupChunkModelRender();
    njCnkAction(&ACTION_Isaak, SPEED_Dragon);
    ResetChunkModelRender();

    njPopMatrix(1u);
}

void DISPLAY_Lyle(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    NJS_ACTION ACTION_Lyle = { MDL_Lyle->getmodel(), ANIM_Lyle->getmotion() };

    njSetTexture(&TEXLIST_STP_Dragons);

    njPushMatrix(0);

    njTranslate(0, twp->pos.x, twp->pos.y + 2.0f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScaleV(0, &SCALE_Dragon);

    SetupChunkModelRender();
    njCnkAction(&ACTION_Lyle, SPEED_Dragon);
    ResetChunkModelRender();

    njPopMatrix(1u);
}

void DISPLAY_Jed(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    NJS_ACTION ACTION_Jed = { MDL_Jed->getmodel(), ANIM_Jed->getmotion() };

    njSetTexture(&TEXLIST_STP_Dragons);

    njPushMatrix(0);

    njTranslate(0, twp->pos.x, twp->pos.y + 2.0f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScaleV(0, &SCALE_Dragon);

    SetupChunkModelRender();
    njCnkAction(&ACTION_Jed, SPEED_Dragon);
    ResetChunkModelRender();

    njPopMatrix(1u);
}

void DISPLAY_Bruno(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    NJS_ACTION ACTION_Bruno = { MDL_Bruno->getmodel(), ANIM_Bruno->getmotion() };

    njSetTexture(&TEXLIST_STP_Dragons);

    njPushMatrix(0);

    njTranslate(0, twp->pos.x, twp->pos.y + 2.0f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScaleV(0, &SCALE_Dragon);

    SetupChunkModelRender();
    njCnkAction(&ACTION_Bruno, SPEED_Dragon);
    ResetChunkModelRender();

    njPopMatrix(1u);
}

void DISPLAY_Cleetus(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    NJS_ACTION ACTION_Cleetus = { MDL_Cleetus->getmodel(), ANIM_Cleetus->getmotion() };

    njSetTexture(&TEXLIST_STP_Dragons);

    njPushMatrix(0);

    njTranslate(0, twp->pos.x, twp->pos.y + 2.0f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScaleV(0, &SCALE_Dragon);

    SetupChunkModelRender();
    njCnkAction(&ACTION_Cleetus, SPEED_Dragon);
    ResetChunkModelRender();

    njPopMatrix(1u);
}


//  Dragons - Exec Functions:

//  NOTE: Since these are child tasks and not SET objects, I use CheckRangeOutWithR to set up a custom range.
//  In this case if (!CheckRangeOutWithR(tp, range)) whichs means: "If the object is not gonna be deleted, do what's in the condition".
//  I don't use CheckRangeOut because this one picks up the range set in the object list, this is not the case for child objects since they are created manually and not part of the object list.

void EXEC_Isaak(task* tp)
{
    if (!CheckRangeOutWithR(tp, 250000.0f))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:

                tp->disp = DISPLAY_Isaak;
                CCL_Init(tp, &COLLI_Isaak, 1, 4u);

                POS_IsaakSmoke.x = twp->pos.x;
                POS_IsaakSmoke.y = twp->pos.y + 18.0f;
                POS_IsaakSmoke.z = twp->pos.z;

                twp->mode++;

                break;

            case 1:

                SPEED_Dragon += 0.33f; // Como?

                if (++twp->wtimer > 425)
                {
                    CreateSmoke(&POS_IsaakSmoke, &VELO_DragonSmoke, 5.0f);
                    FreeTask(tp);
                }

                break;
        }

        EntryColliList(twp);

        tp->disp(tp);
    }
}

void EXEC_Lyle(task* tp)
{
    if (!CheckRangeOutWithR(tp, 250000.0f))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:

                tp->disp = DISPLAY_Lyle;
                CCL_Init(tp, &COLLI_Lyle, 1, 4u);

                POS_LyleSmoke.x = twp->pos.x;
                POS_LyleSmoke.y = twp->pos.y + 15.0f;
                POS_LyleSmoke.z = twp->pos.z;

                twp->mode++;

                break;

            case 1:

                SPEED_Dragon += 0.4f;

                if (++twp->wtimer > 460)
                {
                    CreateSmoke(&POS_LyleSmoke, &VELO_DragonSmoke, 5.0f);
                    FreeTask(tp);
                }

                break;
        }

        EntryColliList(twp);

        tp->disp(tp);
    }
}

void EXEC_Jed(task* tp)
{
    if (!CheckRangeOutWithR(tp, 250000.0f))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:

                tp->disp = DISPLAY_Jed;
                CCL_Init(tp, &COLLI_Jed, 1, 4u);

                POS_JedSmoke.x = twp->pos.x;
                POS_JedSmoke.y = twp->pos.y + 15.0f;
                POS_JedSmoke.z = twp->pos.z;

                twp->mode++;

                break;

            case 1:

                SPEED_Dragon += 0.35f;

                if (++twp->wtimer > 375)
                {
                    CreateSmoke(&POS_JedSmoke, &VELO_DragonSmoke, 5.0f);
                    FreeTask(tp);
                }

                break;
        }

        EntryColliList(twp);

        tp->disp(tp);
    }
}

void EXEC_Bruno(task* tp)
{
    if (!CheckRangeOutWithR(tp, 250000.0f))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:

                tp->disp = DISPLAY_Bruno;
                CCL_Init(tp, &COLLI_Bruno, 1, 4u);

                POS_BrunoSmoke.x = twp->pos.x;
                POS_BrunoSmoke.y = twp->pos.y + 18.0f;
                POS_BrunoSmoke.z = twp->pos.z;

                twp->mode++;

                break;

            case 1:

                SPEED_Dragon += 0.4f;

                if (++twp->wtimer > 440)
                {
                    CreateSmoke(&POS_BrunoSmoke, &VELO_DragonSmoke, 5.0f);
                    FreeTask(tp);
                }

                break;
        }

        EntryColliList(twp);

        tp->disp(tp);
    }
}

void EXEC_Cleetus(task* tp)
{
    if (!CheckRangeOutWithR(tp, 250000.0f))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:

                tp->disp = DISPLAY_Cleetus;
                CCL_Init(tp, &COLLI_Cleetus, 1, 4u);

                POS_CleetusSmoke.x = twp->pos.x;
                POS_CleetusSmoke.y = twp->pos.y + 15.0f;
                POS_CleetusSmoke.z = twp->pos.z;

                twp->mode++;

                break;

            case 1:

                SPEED_Dragon += 0.7f;

                if (++twp->wtimer > 350)
                {
                    CreateSmoke(&POS_CleetusSmoke, &VELO_DragonSmoke, 5.0f);
                    FreeTask(tp);
                }

                break;
        }

        EntryColliList(twp);

        tp->disp(tp);
    }
}


//  Dragons - ChildTaskSet:

childtaskset CTS_Isaak[] = {
    { EXEC_Isaak, 2, 0, {0}, {0}, 0 },
    { 0 }
};

childtaskset CTS_Lyle[] = {
    { EXEC_Lyle, 2, 0, {0}, {0}, 0 },
    { 0 }
};

childtaskset CTS_Jed[] = {
    { EXEC_Jed, 2, 0, {0}, {0}, 0 },
    { 0 }
};

childtaskset CTS_Bruno[] = {
    { EXEC_Bruno, 2, 0, {0}, {0}, 0 },
    { 0 }
};

childtaskset CTS_Cleetus[] = {
    { EXEC_Cleetus, 2, 0, {0}, {0}, 0 },
    { 0 }
};


//  Dragons - Load Assets:

void LOAD_Dragons()
{
    MDL_Spyro = LoadChunkModel("STP_SpyroLEDGE");
    MDL_Isaak = LoadChunkModel("STP_Isaak");
    MDL_Lyle = LoadChunkModel("STP_Lyle");
    MDL_Jed = LoadChunkModel("STP_Jed");
    MDL_Bruno = LoadChunkModel("STP_Bruno");
    MDL_Cleetus = LoadChunkModel("STP_Cleetus");

    ANIM_Spyro = LoadObjectAnim("STP_SpyroLEDGE");
    ANIM_Isaak = LoadObjectAnim("STP_Isaak");
    ANIM_Lyle = LoadObjectAnim("STP_Lyle");
    ANIM_Jed = LoadObjectAnim("STP_Jed");
    ANIM_Bruno = LoadObjectAnim("STP_Bruno");
    ANIM_Cleetus = LoadObjectAnim("STP_Cleetus");
}