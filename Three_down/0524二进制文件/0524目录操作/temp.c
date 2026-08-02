for (int i = 0; i < Elev->internalCount; i++)
{
    // 同为上行方向
    if (Elev->direction == 0)
    {
        // 大于当前楼层的请求，都加入Red数组并升序排序（不是重复请求）
        if (Elev->internalRequests[i] > Elev->externalRequests[i])
        {
            for (int j = 0; j < r_i; j++)
            {
                if (Red[j] == Elev->internalRequests[i])
                {
                    same_Red = 1;
                    break;
                }
            }
            if (!same_Red)
            {
                Red[r_i++] = Elev->internalRequests[i];
            }
            Sort_Red_Top(Red, r_i);
            same_Red = 0;
        } else
        {
            // 小于当前楼层的请求，都加入blue数组并降序排序（不是重复请求）
            for (int j = 0; j < b_i; j++)
            {
                if (blue[j] == Elev->internalRequests[i])
                {
                    same_Blue = 1;
                    break;
                }
            }
            if (!same_Blue)
            {
                blue[b_i++] = Elev->internalRequests[i];
            }
            Sort_Blue_Bottom(blue, b_i);
            same_Blue = 0;
        }
    }
    // 反方向，则看blue数组是否重复
    else
    {
        // 小于当前楼层的请求，都加入blue数组并降序排序（不是重复请求）
        if (Elev->internalRequests[i] < Elev->externalRequests[i])
        {
            for (int j = 0; j < b_i; j++)
            {
                if (blue[j] == Elev->internalRequests[i])
                {
                    same_Blue = 1;
                    break;
                }
            }
            if (!same_Blue)
            {
                blue[b_i++] = Elev->internalRequests[i];
            }
            Sort_Blue_Bottom(blue, b_i);
            same_Blue = 0;
        } else
        {
            // 大于当前楼层的请求，都加入一个新的数组并升序排序
            new_Red[new_r_i++] = Elev->internalRequests[i];
            Sort_Red_Top(new_Red, new_r_i);
            same_Red = 0;
        }
    }

    // 到达翻转的位置
    if (i == turn)
    {
        Elev->direction = 1;
    }
}
// 最后把Red，blue，new_Red数组合并到finalTargets数组中
for (int j = 0; j < r_i; j++)
{
    Elev->finalTargets[j] = Red[j];
}
for (int j = 0; j < b_i; j++)
{
    Elev->finalTargets[r_i + j] = blue[j];
}
for (int j = 0; j < new_r_i; j++)
{
    Elev->finalTargets[r_i + b_i + j] = new_Red[j];
}