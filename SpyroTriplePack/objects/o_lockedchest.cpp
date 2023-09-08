#include "pch.h"

//  Models, Collisions and Text Messages - Note: Used the acronym "LKC which stands for LocKed Chest", the Life Chest was already using the LC acronym.

ModelInfo* MDL_LockedChest = nullptr;

ModelInfo* MDL_LKCLid = nullptr;
ModelInfo* MDL_LKCDebris01 = nullptr;
ModelInfo* MDL_LKCDebris02 = nullptr;
ModelInfo* MDL_LKCDebris03 = nullptr;
ModelInfo* MDL_LKCDebris04 = nullptr;
ModelInfo* MDL_Number50 = nullptr;

ModelInfo* MDL_LKCKey = nullptr;

ModelInfo* MDL_LKCColli01 = nullptr;
ModelInfo* MDL_LKCColli02 = nullptr;

CCL_INFO COLLI_LKCKey = { 0, CollisionShape_Sphere, 0xF0, 0, 0, { 0.0f, 4.625f, 0.0f }, 4.625f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };

NJS_VECTOR POS_LKCTrigger = { 0, 0, 0 };

const char** MSG_LockedChest;

const char* MSG_LockedChest_EN[] = {
    "You need a key to open this chest!",
    NULL,
};

const char* MSG_LockedChest_JP[] = {
    "\a\202\261\202\314\225\363\224\240\202\360\212\112\202\257\202\351\202\311\202\315\214\256\202\252\225\113\227\166\202\305\202\267\201\111",
    NULL,
};


//  Locked Chest - Rewards:

void SetLKCOpen()
{
    AddEnemyScore(2000);
    dsPlay_oneshot(SE_BOMB, 0, 0, 0);
    AddNumRing(50);
    HasKey = 0;
}


//  Locked Chest Key - Main:

void KeyPickup()
{
    AddEnemyScore(100);
    dsPlay_oneshot(SE_ITEMGET, 0, 0, 0);
    HasKey = 1;
}

void DISPLAY_LKCKey(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_LKCKey->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_LKCKey(task* tp)
{
    auto twp = tp->twp;

    if (CheckRangeOut(tp))
        return;

    switch (twp->mode)
    {
        case 0:

            SetNoRevive(tp);
            
            tp->disp = DISPLAY_LKCKey;
            CCL_Init(tp, &COLLI_LKCKey, 1, 4u);

            twp->mode++;

            break;

        case 1:

            twp->ang.y += 750;
            
            if (twp->flag & Status_ObjectInteract && twp->cwp->hit_cwp)
            {
                task* hit_tp = twp->cwp->hit_cwp->mytask;

                if (hit_tp && IsThisTaskPlayer(hit_tp) != -1)
                {
                    KeyPickup();

                    DeadOut(tp); // This will kill the object on contact, so there's no need to setup a FreeTask(tp); timer on another case like when using Dead(tp);

                    twp->mode++;
                }
            }
            
            break;
    }

    EntryColliList(twp);
    
    tp->disp(tp);
}


//  Locked Chest Body - Main:

void DISPLAY_LockedChest(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_LockedChest->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_LockedChest(task* tp)
{
    if (CheckRangeOut(tp))
        return;

    auto twp = tp->twp;

    if (!twp->mode)
    {
        auto object = GetMobileLandObject();

        tp->disp = DISPLAY_LockedChest;
        tp->dest = B_Destructor;

        object->pos[0] = twp->pos.x;
        object->pos[1] = twp->pos.y;
        object->pos[2] = twp->pos.z;

        object->ang[0] = twp->ang.x;
        object->ang[1] = twp->ang.y;
        object->ang[2] = twp->ang.z;

        object->scl[0] = 1.0f;
        object->scl[1] = 1.0f;
        object->scl[2] = 1.0f;

        object->basicdxmodel = MDL_LKCColli01->getmodel()->basicdxmodel;

        RegisterCollisionEntry(ColFlags_Solid, tp, object);

        twp->counter.ptr = object;

        twp->mode++;
    }

    MirenObjCheckCollisionP(twp, 100.0f);
    
    tp->disp(tp);
}


//  Locked Chest - Debris Pieces:

void DISPLAY_LKCDebris(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);

    if (twp->ang.x)
        njRotateX(0, twp->ang.x);

    if (twp->ang.y)
        njRotateY(0, twp->ang.y);

    ds_DrawObjectClip((NJS_OBJECT*)twp->counter.ptr, 1.0f);
    
    njPopMatrix(1);
}

void EXEC_LKCDebris(task* tp)
{
    if (!CheckRangeOutWithR(tp, 96100.0))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:
                
                tp->disp = DISPLAY_LKCDebris;
                
                twp->mode = 1;

                twp->scl.x = njRandom() - 0.5f;
                twp->scl.y = njRandom() + 0.5f;
                twp->scl.z = njRandom() - 0.5f;
                
                break;
           
            case 1:
                
                twp->pos.x += twp->scl.x;
                twp->pos.y += twp->scl.y;
                twp->pos.z += twp->scl.z;

                twp->ang.x += 0x80;
                twp->ang.y += 0x100;

                twp->scl.y -= 0.05f;
                
                break;
        }

        tp->disp(tp);
    }
}

childtaskset CTS_LKCDebris[] = {
    { EXEC_LKCDebris, 2, 0, {0}, {0}, 0 },
    { EXEC_LKCDebris, 2, 0, {0}, {0}, 0 },
    { EXEC_LKCDebris, 2, 0, {0}, {0}, 0 },
    { EXEC_LKCDebris, 2, 0, {0}, {0}, 0 },
    { 0 }
};


//  Locked Chest - Value Number:

void DISPLAY_Number50(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_Number50->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_Number50(task* tp)
{
    if (!CheckRangeOutWithR(tp, 96100.0))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:
                
                tp->disp = DISPLAY_Number50;
                
                twp->mode++;
                
                break;
           
            case 1:
                
                twp->ang.y += 750;
                
                break;
        }

        tp->disp(tp);
    }
}

childtaskset CTS_Number50[] = {
    { EXEC_Number50, 2, 0, {0}, {0}, 0 },
    { 0 }
};


//  Chest Lid - Main:

void DISPLAY_LKCLid(task* tp)
{
    if (MissedFrames)
        return;
    
    auto twp = tp->twp;

    if (twp->mode == 3)
        return;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_LKCLid->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_LKCLid(task* tp)
{
    auto twp = tp->twp;
    
    if (CheckRangeOut(tp))
        return;

    switch (twp->mode)
    {
        case 0:
        {
            SetNoRevive(tp);

            auto object = GetMobileLandObject();

            tp->disp = DISPLAY_LKCLid;
            tp->dest = B_Destructor;

            // Dyncol code:
            object->pos[0] = twp->pos.x;
            object->pos[1] = twp->pos.y;
            object->pos[2] = twp->pos.z;

            object->ang[0] = twp->ang.x;
            object->ang[1] = twp->ang.y;
            object->ang[2] = twp->ang.z;

            object->scl[0] = 1.0f;
            object->scl[1] = 1.0f;
            object->scl[2] = 1.0f;

            object->basicdxmodel = MDL_LKCColli02->getmodel()->basicdxmodel;

            RegisterCollisionEntry(ColFlags_Solid, tp, object);

            twp->counter.ptr = object;

            //  Invisible trigger location code (for the chest lock):
            POS_LKCTrigger.x = twp->pos.x + njSin(twp->ang.y) * 20.0f;
            POS_LKCTrigger.y = twp->pos.y + 8.25f;
            POS_LKCTrigger.z = twp->pos.z + njCos(twp->ang.y) * 20.0f;

            twp->mode++;

            break;
        }

        case 1:
        {
            if (CheckCollisionP(&POS_LKCTrigger, 10.0f))
            {
                if (HasKey == 0)
                {
                    dsPlay_oneshot(SE_P_JUMP2, 0, 0, 0);
                    
                    MSG_LockedChest = (Language != JAPANESE) ? MSG_LockedChest_EN : MSG_LockedChest_JP;
                    DisplayHintText(MSG_LockedChest, 100);

                    twp->mode = 2;
                }

                else
                {
                    SetLKCOpen();

                    Dead(tp);

                    CreateChildrenTask(CTS_LKCDebris, tp);
                    CreateChildrenTask(CTS_Number50, tp);

                    //  Necessary functions to kill a dyncol early:
                    WithdrawCollisionEntry(tp, (NJS_OBJECT*)twp->counter.ptr);
                    ReleaseMobileLandObject((NJS_OBJECT*)twp->counter.ptr);

                    twp->mode = 3;
                }
            }

            break;
        }

        case 2:
        {
            if (++twp->wtimer > 150)
            {
                twp->wtimer = 0;

                twp->mode = 1;
            }

            break;
        }

        case 3:
        {            
            if (++twp->wtimer > 120)
                FreeTask(tp);

            LoopTaskC(tp);

            break;
        }
    }
    
    MirenObjCheckCollisionP(twp, 100.0f);

    tp->disp(tp);
}


//  Locked Chest & Chest Key - Load Assets:

void LOAD_LockedChest()
{
    MDL_LockedChest = LoadBasicModel("STP_LockedChest");
    MDL_LKCLid = LoadBasicModel("STP_LKCLid");
    MDL_LKCDebris01 = LoadBasicModel("STP_LKCDebris01");
    MDL_LKCDebris02 = LoadBasicModel("STP_LKCDebris02");
    MDL_LKCDebris03 = LoadBasicModel("STP_LKCDebris03");
    MDL_LKCDebris04 = LoadBasicModel("STP_LKCDebris04");
    MDL_Number50 = LoadBasicModel("STP_Number50");
    MDL_LKCKey = LoadBasicModel("STP_LKCKey");
    MDL_LKCColli01 = LoadBasicModel("STP_LKCColli01");
    MDL_LKCColli02 = LoadBasicModel("STP_LKCColli02");

    CTS_LKCDebris[0].ptr = MDL_LKCDebris01->getmodel();
    CTS_LKCDebris[1].ptr = MDL_LKCDebris02->getmodel();
    CTS_LKCDebris[2].ptr = MDL_LKCDebris03->getmodel();
    CTS_LKCDebris[3].ptr = MDL_LKCDebris04->getmodel();
}